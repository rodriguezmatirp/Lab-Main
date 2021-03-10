import socket
from hamming_code import decode_hamming_code

LOCALHOST = '127.0.0.1'
PORT = 65432

if __name__ == '__main__':

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:

        sock.bind((LOCALHOST, PORT))
        sock.listen()

        while True:
            conn, addr = sock.accept()
            print('Connection address : ', addr)
            hamming_code = conn.recv(1024).decode('utf-8')
            if hamming_code :
                decoded_data, msg = decode_hamming_code(hamming_code)
                print(decoded_data,msg)

