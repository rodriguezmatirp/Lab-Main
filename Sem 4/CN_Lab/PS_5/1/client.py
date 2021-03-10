import socket
from hamming_code import generate_hamming_code

LOCALHOST = '127.0.0.1'
PORT = 65432

if __name__ == '__main__':
    
    word = input('Enter the dataword : ')

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:

        sock.connect((LOCALHOST, PORT))
        query_data = generate_hamming_code(word)
        if query_data:
            sock.sendall(bytes(query_data,'utf-8'))
