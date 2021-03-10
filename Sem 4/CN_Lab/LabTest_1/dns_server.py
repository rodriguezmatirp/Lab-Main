import socket
import subprocess

LOCALHOST = '127.0.0.1'
PORT = 65432

def commands(req_code, option, address):
    global mac_table
    req_code = req_code.upper()
    if req_code == 'DOMAIN_NAME':
        domain_ip = subprocess.check_output(f'dig +short {option}',shell=True)
        if domain_ip :
            return bytes(domain_ip, 'utf-8')
        else:
            return b'Provide proper domain name'
    elif req_code == 'MAC':
        mac_table[address] = option
        return bytes(f'Added {address} - {option} to Server MAC table','utf-8')
    elif req_code == 'TABLE':
        return bytes(str(mac_table),'utf-8')
    else:
        return b'Invalid Request Code'

if __name__ == '__main__':
    mac_table = {}
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind((LOCALHOST, PORT))
        s.listen()

        while True:
            conn, addr = s.accept()
            print('Client address : ', addr)
            while True:
                request = conn.recv(100).decode('utf-8').split()
                if request:
                    if len(request) == 2 :
                        response = commands(request[0], request[1], addr)
                        conn.sendall(response)
                    elif request[0].lower() == 'table':
                        response = commands(request[0], '', addr)
                        conn.sendall(response)
                    elif request[0] == 'exit':
                        print(f'Client Connection -  {addr} closed')
                        break
                    else:
                        conn.sendall(b'Invalid Request Code or Options')
