def has22(array):
    for x in range(len(array) -1) :
        if array[x] == 2 and array[x+1] ==2 :
            return True
    return False

if __name__ == '__main__':
    length = int(input('Enter length of list : '))
    input_list = []
    print('Enter the elements : ')
    for x in range(length) :
        input_list.append(input())
    if has22(input_list) :
        print('True')
    else:
        print('False')
