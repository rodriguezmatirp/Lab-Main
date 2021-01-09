def duplicate(list_1):
    result = []
    for i in list_1:
        if i not in result:
            result.append(i)
    return result

if __name__ == '__main__':
    input_list = input('Enter the list : ')
    input_list = input_list.split()
    print(duplicate(input_list))