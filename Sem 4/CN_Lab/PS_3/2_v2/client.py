import socket

UDP_IP = "127.0.0.1"
UDP_PORT = 65432
MESSAGE = b"Connection Successful"

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))
    data, address = sock.recvfrom(1024)
    if data:
        print(data)
    while(True):
        msg = input()
        sock.sendto(bytes(msg, 'utf-8'), (UDP_IP, UDP_PORT))
        data, address = sock.recvfrom(1024)
        if data:
            print(data)
