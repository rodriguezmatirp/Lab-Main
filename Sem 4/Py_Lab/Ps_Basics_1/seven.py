def check_pangram(input_str):
    input_str = set(input_str.lower())
    unique_char_set = [ x for x in input_str if ord(x) in range(ord('a'),ord('z') +1)]
    if len(unique_char_set) == 26:
        return True
    return False

if __name__ == '__main__':
    input_str = input('Enter a string : ')
    if check_pangram(input_str) :
        print('Yes, It is!')
    else :
        print('Nope!')
