def caesar_cipher(plain_text, key):
    result = []
    for x in plain_text:
        if 64 < ord(x) < 91:
            if ord(x) + key > 90:
                x = chr(64 + (ord(x) + key)%90)
            else:
                x = chr(ord(x) + key)
        if 96 < ord(x) < 123:
            if ord(x) + key > 122:
                x = chr(96 + (ord(x) + key)%122)
            else:
                x = chr(ord(x) + key)
        result.append(x)
    return "".join(result)



if __name__ == '__main__':
    user_input = input('Enter a plain text to encrypt : ')  
    key = int(input('Enter the key : '))
    encrypted = caesar_cipher(user_input,key)
    print(encrypted)