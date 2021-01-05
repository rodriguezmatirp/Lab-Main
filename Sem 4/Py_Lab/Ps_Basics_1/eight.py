def run_length_encoding(data):
    possible_values = ['B', 'W']
    encoded = []
    count = 0
    prev = data[0]
    for x in range(len(data)) :
        if data[x] in possible_values and data[x] == prev :
            count += 1
            prev = data[x] 
            if x == len(data)-1 :
                encoded.append(f'{count}{prev}')   
        else :
            encoded.append(f'{count}{prev}')
            count = 1
            prev = data[x]

    return encoded

if __name__ == '__main__':
    data = input()
    encoded = run_length_encoding(data)
    print("".join(encoded))