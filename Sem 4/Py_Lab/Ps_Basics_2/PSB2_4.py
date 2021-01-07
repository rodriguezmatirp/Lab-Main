if __name__ == '__main__' :
    sentence_1 = input('Enter list : ')
    list_1 = set(sentence_1.split())
    print(f'max value - {max(list_1)}')
    print(f'min value - {min(list_1)}')