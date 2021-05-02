from scapy.all import *
import time
from threading import Thread

class ClientPayload:    
    def __init__(self, request_command, seq_num):
        self.command = request_command
        self.sequence_number = seq_num
        self.sent_time = time.time()
        self.recv_time = -1
    
    def __str__(self):
        return f'{self.command} {self.sequence_number} {self.sent_time} {self.recv_time}'

def send_packets(count,command,timeout):
    global PKTS
    for seq_num in range(count):
        client_pl = ClientPayload(command, seq_num)
        PKTS.append(client_pl)
        packet = IP(dst='www.google.com')/ICMP()/str(client_pl)
        send(packet,verbose=0)
        if time.time() - client_pl.sent_time < 1:
            time.sleep(1 - time.time() + client_pl.sent_time)

def check_pkt(pkt):
    global PKTS
    global RECEIVE_SEQ
    if pkt[2].type == 0:
        pkt_seq = int(pkt[3].load.decode('utf-8').split()[1])
        if 0 <= pkt_seq < 10 :
            PKTS[pkt_seq].recv_time = time.time()
            RECEIVE_SEQ.append(str(PKTS[pkt_seq]))

def report(recieved_pkts,request_count):
    global PKTS
    failure_count = 0
    rtt_count = 0
    recvd_seq = [x.split()[1] for x in recieved_pkts]

    for x in PKTS:
        seq_num = x.sequence_number
        rtt = x.recv_time - x.sent_time
        if str(seq_num) not in recvd_seq or rtt > 1 :
            print(f'{seq_num} Timed_Out')
            failure_count += 1
        else :
            print(f'{seq_num} {PKTS[seq_num].recv_time} {str(PKTS[seq_num])} "Successfully_Recieved" {(PKTS[seq_num].recv_time - PKTS[seq_num].sent_time)*1000} ms')
            rtt_count += PKTS[seq_num].recv_time - PKTS[seq_num].sent_time

    print(f'Loss Rate : {(failure_count/request_count)*100} %')
    if failure_count != request_count:
        print(f'Average RTT : {(rtt_count/(request_count-failure_count))*1000} ms')

if __name__ == '__main__':
    REQUEST_COUNT = 3
    REQUEST_TIMEOUT = 1
    REQUEST_COMMAND = 'MY_PING'

    RECEIVE_SEQ = []
    PKTS = []

    thread = Thread(target=send_packets,args=(REQUEST_COUNT,REQUEST_COMMAND,REQUEST_TIMEOUT))
    thread.start()

    recvd = sniff(count=2*REQUEST_COUNT, filter='icmp',prn=check_pkt, timeout=REQUEST_COUNT)

    # print(recvd,RECEIVE_SEQ)

    report(RECEIVE_SEQ,REQUEST_COUNT)
