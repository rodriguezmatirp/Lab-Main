def most_frequent(string):
    frequency = {}
    for x in string:
        if x in frequency:
            frequency[x] +=1
        else :
            frequency[x] = 1
    sorted_dict = {}
    sorted_keys = sorted(frequency,key=frequency.get,reverse=True)
    for x in sorted_keys:
        sorted_dict[x] = frequency[x]
    result = [x[0] for x in sorted_dict]
    return result

if __name__ =='__main__':
    string = input('Enter a string : ')
    print(most_frequent(string))
