def maximum(input_list):
    if len(input_list) == 1:
        return input_list[0]
    else:
        value_now = maximum(input_list[1:])
        if input_list[0] > value_now:
            return value_now
        return max_value

if __name__ == '__main__':
    input_list = list(input('Enter the list : ').split())
    max_value = maximum(input_list)
    print(max_value)