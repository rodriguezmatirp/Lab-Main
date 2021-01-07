def clear_set(set_1):
    return set_1.clear()

if __name__ == '__main__' :
    sentence_1 = input('Enter list : ')
    list_1 = set(sentence_1.split())
    print(f'set before clearing - {list_1}')
    print(f'set after clearing  - {clear_set(list_1)}')