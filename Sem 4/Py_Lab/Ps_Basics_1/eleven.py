def keprekar(number):
    sqr_num = number*number
    numbers = list(sqr_num)
    n = len(str(number))
    list_1 = numbers[ : n]
    list_2 = numbers[ : len(numbers) - n]
    num_1 = int("".join(list_1))
    num_2 = int("".join(list_2))
    if number == num_1 + num_2:
        return True
    return False

