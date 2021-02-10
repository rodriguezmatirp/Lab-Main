def divide_list(list_,n):
    if n != 0:    
        if len(list_) % 3 == 2:
            n += 1
        for i in range(0,len(list_),n):
            if list_[i] != '':
                if len(list_) % 3 == 1:
                    if i == 2*n:
                        yield list_[i: i+n+1]
                        break
                yield list_[i: i+n]

if __name__ == '__main__':
    user_input = list(input('Enter the list : ').split(" "))   
    result = []
    if len(user_input) > 2:
        # user_input = list(divide_list(user_input , int(len(user_input)/3)))
        for x in divide_list(user_input,int(len(user_input)/3)):
            x.reverse()
            result.append(x)
        # for x in user_input:
            # x.reverse()
    else:
        user_input.reverse()
        result = user_input
    print(result)
