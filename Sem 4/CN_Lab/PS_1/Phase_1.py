#Transposition Cipher - Rail Fence Cryptography
def fence(lst, numrails):
    fence = [[None] * len(lst) for n in range(numrails)]
    rails = range(numrails) 
    for n, x in enumerate(lst):
        fence[rails[n % len(rails)]][n] = x
    # print(fence)

    return [c for rail in fence for c in rail if c is not None]

def encryption(n):
    f = open('A.txt','r')
    data = f.read()
    f.close()

    f = open('B.txt','w')
    f.write(''.join(fence(data,n)))
    f.close()

    return ''.join(fence(data, n))

def decryption(n):
    f = open('B.txt','r')
    data = f.read()
    f.close()

    rng = range(len(data))
    pos = fence(rng, n)

    f = open('C.txt','w')
    f.write(''.join(data[pos.index(n)] for n in rng))
    f.close()

    return ''.join(data[pos.index(n)] for n in rng)

if __name__ == '__main__':
    inp_str = input('Enter the string to encrypt : ')
    key = int(input('Enter the key : '))
    
    f = open('A.txt','w')
    f.write(inp_str)
    f.close()

    encrypted = encryption(key)
    print(f'Encrypted string - {encrypted}')

    decrypted = decryption(key)
    print(f'Decrypted string - {decrypted}')
