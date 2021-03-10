import socket
import crc

LOCALHOST = '127.0.0.1'
PORT = 65432

if __name__ == '__main__':

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:

        sock.bind((LOCALHOST, PORT))
        sock.listen()

        while True:
            conn, addr = sock.accept()
            print('Connection address : ', addr)
            received_data = conn.recv(100).decode('utf-8').split(' ')
            codeword = received_data[0]
            key = received_data[1]
            if codeword and key:
                remainder = crc.decode(codeword,key)
                if '1' in remainder:
                    print('Error Detected')
                else:
                    print('No error Detected')