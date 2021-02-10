import socket

UDP_IP = "127.0.0.1"
UDP_PORT = 65432
MESSAGE = b"Hello, from client"

with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as sock:

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.sendto(MESSAGE, (UDP_IP, UDP_PORT))
    data, address = sock.recvfrom(1024)
    if data:
        print(data)
    