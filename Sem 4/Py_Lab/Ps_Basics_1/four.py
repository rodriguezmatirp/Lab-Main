if(__name__ == '__main__'):
    S,num,char = list(input()),int(input()), input()
    S[num] = char
    #concat empty string with list of characters
    print("".join(S))
