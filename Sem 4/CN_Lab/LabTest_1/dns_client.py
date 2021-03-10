import socket

LOCALHOST = '127.0.0.1'
PORT = 65432
BUFFER_SIZE = 1024

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
    sock.connect((LOCALHOST, PORT))

    while True:
        try:
            query = input('[REQUESTCODE OPTION] : ')
            sock.sendall(bytes(query,'utf-8'))
            if query == 'exit':
                break
            response = sock.recv(BUFFER_SIZE).decode('utf-8')
            if response:
                print(f'Server : {response}')
        except KeyboardInterrupt:
            exit(1)

    # print("Received data :", data.decode('utf-8'))

'''
Valid Test cases :
domain_name www.google.com      //returns the ip address of the domain name 
mac xyz                         //stores the address and mac locally
table                           //returns server's mac_table
'''