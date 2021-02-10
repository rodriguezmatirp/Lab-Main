import socket
import os

HOST = '127.0.0.1'
PORT = 65432


with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
    sock.bind((HOST, PORT))
    print("Listening for messages")
    
    while(True):
        data, address = sock.recvfrom(1024)

        print(data)
        print(address)

        if data:
            server_ping = os.system('ping -c 1 ' + HOST)
            if server_ping == 0:
                msg = 'Server Reached'
            else:
                msg = 'Server not reached'
            
            sock.sendto(b'Message recieved - ' + bytes(msg,"utf-8"), address)
    sock.close()