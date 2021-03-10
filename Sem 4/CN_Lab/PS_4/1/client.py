import socket

LOCALHOST = '127.0.0.1'
PORT = 65432
BUFFER_SIZE = 1024

query = input('Enter the request code - ')

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        
    s.connect((LOCALHOST, PORT))
    s.send(bytes(query,'utf-8'))
    data = s.recv(BUFFER_SIZE)

    print ("Received data :", data.decode('utf-8'))
    s.close()
