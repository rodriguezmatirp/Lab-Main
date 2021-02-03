#Encrypting Uppercase letter
def caesar_cipher(text,shift_pattern = 3):
    encryption = ""
    for x in text:
        if x.isupper():
            x_index = ord(x)-ord("A")
            new_index = (x_index + shift_pattern)%26
            encryption += chr(new_index+ord("A"))
        else:
            encryption +=x
    return encryption

print(caesar_cipher('THE TEXT TO BE ENCRYPTED'))
