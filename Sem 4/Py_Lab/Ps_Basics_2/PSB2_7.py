def check_whether_equal(set_1,set_2):
    return set(set_1) == set(set_2)

if __name__ == '__main__' :
    sentence_1 = input('Enter set 1 : ')
    set_1 = set(sentence_1.split())
    sentence_2 = input('Enter set 2 : ')
    set_2 = set(sentence_2.split())
    if check_whether_equal(set_1,set_2):
        print('Yes, Sets are equal!')
    else :
        B1 = set_2 - set_1
        B2 = set_1 - set_2
        print(f'B1 - {B1}')
        print(f'B2 - {B2}')