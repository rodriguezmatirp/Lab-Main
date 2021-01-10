def keprekar(number):
    sqr_num = number*number
    numbers = list(str(sqr_num))
    n = len(str(number))
    list_1 = numbers[ -1*n : ]
    list_2 = numbers[ : -1* n]
    num_1 = int("".join(list_1))
    num_2 = int("".join(list_2))
    if number == num_1 + num_2:
        return True
    return False