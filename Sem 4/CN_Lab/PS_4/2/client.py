import socket
from threading import Thread

def recieve_messages(sock):
    while True:
        recv_msg = sock.recv(50).decode('utf-8')
        if recv_msg == 'Closed':
            break
        if recv_msg:
            print('\n' + recv_msg + '\n'+ 'Me : ')                                      

if __name__ == '__main__':
    HOST = '127.0.0.1'
    PORT =  65432

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.connect((HOST,PORT))
        username = input('Enter username : ')
        if username == '': username = 'Guest'
        sock.send(bytes(username,'utf-8'))
        data = sock.recv(50)
        print(data.decode('utf-8'))
        
        try:
            thread = Thread(target=recieve_messages, args=(sock,))
            thread.start()
        except :
            print("Error in thread creation")

        while True:
            try :
                msg = input('Me : ')
                sock.sendall(bytes(msg,'utf-8'))
                if msg == 'exit' or msg == '':
                    break
            except KeyboardInterrupt:
                exit(1)