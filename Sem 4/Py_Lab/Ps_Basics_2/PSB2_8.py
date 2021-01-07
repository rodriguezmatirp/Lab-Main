def intersection(set_1,set_2):
    return set(set_1).intersection(set_2)

def union(set_1,set_2):
    return set(set_1).union(set_2)

def difference(set_1,set_2):
    return set(set_1).difference(set_2)

def symmetric_difference(set_1,set_2):
    return set(set_1).symmetric_difference(set_2)

if __name__ == '__main__' :
    sentence_1 = input('Enter set 1 : ')
    set_1 = set(sentence_1.split())
    sentence_2 = input('Enter set 2 : ')
    set_2 = set(sentence_2.split())
    print(f'Intersection - {intersection(set_1,set_2)}')
    print(f'Union - {union(set_1,set_2)}')
    print(f'Difference - {difference(set_1,set_2)}')
    print(f'Symmetric difference - {symmetric_difference(set_1,set_2)}')