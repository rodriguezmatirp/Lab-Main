from scapy.all import *
import time

def trace_route(ttl_count,dst= "https://google.com"):
    FLAG = True
    while FLAG:
        sent_time = time.time()
        packet = IP(dst=dst,ttl=ttl_count)/ICMP()/'hello'
        reply = sr1(packet,verbose=0,timeout=5)
        recv_time = time.time()

        if reply == None:
            print(f'hops - {ttl_count}')
        
        else:
            rtt = (recv_time - sent_time)*1000
            print(f'hops - {ttl_count} : {reply[0].src} {round(rtt,1)} ms')

            if reply[ICMP].type != 11:
                print('Status - Completed')
                FLAG = False
        
        ttl_count += 1

if __name__ == '__main__':
    TTL = 1
    DESTINATION = 'www.google.com'

    user_dest = input('Destination : (Enter for defaults : google.com)')

    if user_dest :
        DESTINATION = user_dest

    trace_route(TTL,DESTINATION)