def intersection(list_1,list_2):
    return list(set(list_1) & set(list_2))

if __name__ == '__main__' :
    sentence_1 = input('Enter list 1 : ')
    list_1 = list(sentence_1.split())
    sentence_2 = input('Enter list 2 : ')
    list_2 = list(sentence_2.split())
    print(interestion(list_1,list_2))    