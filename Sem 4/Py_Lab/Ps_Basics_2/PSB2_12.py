if __name__ == '__main__':
    input_list = input('Enter the list : ')
    input_list = input_list.split()
    new_list = [x for x in input_list if int(x)%2 == 0]
    print(new_list)