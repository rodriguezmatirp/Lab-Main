import socket
import crc

LOCALHOST = '127.0.0.1'
PORT = 65432

if __name__ == '__main__':

    word = input('Enter the dataword : ')
    
    #Key input format - x**r + x**s + ..., where r,s = 0,1,2,etc.
    key = input('Generator polynomial : ')

    key = crc.convert_gx(key)
    encoded_data = crc.encode(word,key)

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:

        sock.connect((LOCALHOST, PORT))
        if encoded_data :
            data_to_be_sent = encoded_data + ' ' + key
            sock.send(data_to_be_sent.encode())
