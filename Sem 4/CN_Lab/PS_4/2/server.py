import socket
from threading import Thread

def handle_client(conn, addr, username):
    global users
    conn.sendall(b'Welcome to the chatroom\nTo exit type "exit"')
    # print(users)
    broadcast(f'New user has joined!\nSay Hi to {username}', addr, 'Server')
    while True:
        message = conn.recv(1024).decode('utf-8')
        if message.lower() == 'exit':
            remove_client(addr)
            break
        elif message :
            # print(f'{addr} : {message}')
            broadcast(message, addr, username)

def broadcast(message, addr, username):
    global users
    for client in users:
        if client != addr:
            users[client][0].sendall(bytes(f'{username} : {message}','utf-8'))


def remove_client(client_addr):
    global users
    if client_addr in list(users.keys()):
        users[client_addr][0].sendall(b'Closed')
        broadcast(f'{users[client_addr][1]} left!', client_addr, 'Server')
        users[client_addr][0].close()
        del users[client_addr]

if __name__ == '__main__':
    HOST = '127.0.0.1'
    PORT = 65432

    users = {}

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        sock.bind((HOST,PORT))
        sock.listen()

        while True:
            try:
                conn, addr = sock.accept()
                data = conn.recv(1024).decode('utf-8')
                if data:
                    users[addr] = [conn,data]
                    print(f'Client Connected - {addr} : Username - {data}')
                    thread = Thread(target=handle_client,args=(conn, addr,data))
                    thread.start()
            except KeyboardInterrupt:
                break
