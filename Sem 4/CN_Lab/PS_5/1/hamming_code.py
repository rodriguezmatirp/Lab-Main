#Even Parity

def count_parity(bits_count):
    pb = 0
    while bits_count + pb + 1 > pow(2, pb):
        pb += 1
    return pb

def find_parity(word, pb):
    for x in range(pb):
        parity_bit = word[2**x -1]
        inc = 1
        y = 2**x -1
        while y < len(word):
            if inc <= pow(2, x):
                parity_bit = parity_bit ^ word[y]
                inc += 1
                y += 1
            else:
                inc = 1
                y += pow(2, x) 
        word[(2**x - 1)] = parity_bit
    return word

def generate_hamming_code(word):

    bits = list(int(x) for x in word)
    bits.reverse()
    parity_bits = count_parity(len(bits))

    for x in range(parity_bits):
        bits.insert(2**x - 1, 0)

    result = list(str(x) for x in find_parity(bits, parity_bits))

    return "".join(result)

def detect_error(data, pb):
    check = find_parity(data,pb)

    for x in range(len(data)):
        if check[x] != data[x]:
            return x
    return -1

def correct_data(data,pos,pb):
    msg = 'No error detected'
    if pos != -1:
        data[pos] = data[pos] ^ 1
        msg = 'Error Detected'
    for x in range(pb ,0,-1):
        data.pop(2**(x-1)-1)
    data.reverse()
    
    return "".join(list(str(x) for x in data)),msg

def decode_hamming_code(data):
    data = list(int(x) for x in data)
    pb = 0
    while (2**pb) <= len(data):
        pb += 1
    pos = detect_error(data,pb)
    return correct_data(data,pos,pb)


