#Encrypt
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes

#encrypt
def encrption(key) :
    f = open('A.txt','r')
    data = f.read()
    f.close()

    cipher = AES.new(key, AES.MODE_EAX)
    nonce = cipher.nonce
    ciphertext = cipher.encrypt(data.encode("utf-8"))

    f = open('B.txt', "wb")
    [f.write(x) for x in (nonce, ciphertext)]
    f.close()
    return True

#Decrypt
def decryption(key) :
    f = open('B.txt','rb')
    nonce, ciphertext = [f.read(x) for x in (16, -1)]
    f.close()

    cipher = AES.new(key,AES.MODE_EAX,nonce)
    text = cipher.decrypt(ciphertext)
    print(f"Decrypted Text - {text.decode('utf-8')}")

    f = open('C.txt', "w")
    f.write(text.decode('utf8'))
    f.close()

    return True

if __name__ == "__main__":
    inp_str = input('Enter the string : ')

    f = open('A.txt','w')
    f.write(inp_str)
    f.close()
    print('String written in A.txt\n')
    key = b'12345678123456781234567812345678'

    encrption(key)
    decryption(key)
