import socket
import subprocess
import os 

LOCALHOST = '127.0.0.1'
PORT = 65432

def commands(args):
    query = args.decode('UTF-8').upper()
    if query == 'R':
        routing_table = subprocess.check_output(["ip", "route", "list"])
        return routing_table
    elif query =='S':
        tcp_sockets = subprocess.check_output(["ss -s | grep TCP"],shell=True)
        udp_sockets = subprocess.check_output(["ss -s | grep UDP"], shell=True)
        return tcp_sockets + udp_sockets
    elif query == 'A':
        arp_cache = subprocess.check_output(["ip neigh"],shell=True)
        return arp_cache
    else:
        return b'Invalid Code'

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:

    s.bind((LOCALHOST, PORT))
    s.listen()

    while True:
        conn, addr = s.accept()
        print('Connection address :', addr)

        data = conn.recv(20)
        response = commands(data)
        conn.sendall(response)
    conn.close()



