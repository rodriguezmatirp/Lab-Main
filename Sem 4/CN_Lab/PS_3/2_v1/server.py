import socket

HOST = '127.0.0.1'
PORT = 65432

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:
    sock.bind((HOST, PORT))
    print(f"Listening for messages : Host - {HOST} Port - {PORT}")

    while(True):
        data, address = sock.recvfrom(1024)
        print(address)
        if data:
            sock.sendto(data, address)
        