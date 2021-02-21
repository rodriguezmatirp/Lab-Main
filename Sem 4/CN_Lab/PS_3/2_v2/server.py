import socket
from threading import Thread

class UDPServerMultiClient:

    def __init__(self,host,port):
        self.sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
        self.sock.bind((host,port))
        # self.client_list = []
    
    def send_message_back(self,message,address):
        self.sock.sendto(message,address)
    
    def listen_clients(self):
        while True:
            data, address = self.sock.recvfrom(1024)
            print(address,data)
            if data:
                new_thread = Thread(target=self.send_message_back,args=(data,address,))
                new_thread.start()
            #     if address not in self.client_list:
            #         self.client_list.append(address)
            # print(self.client_list)

if __name__=='__main__':
    clients = UDPServerMultiClient('127.0.0.1',65432)
    clients.listen_clients()
