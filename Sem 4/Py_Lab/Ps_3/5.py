def func1(n):
    result = 0
    for i in range(n):
        x = '2'*(i+1)
        result += int(x)
    return result

def func2(n):
    result = 0
    for i in range(n+1):
        result += i*10**(n-i)
    return 2*result

if __name__ == '__main__':
    n = int(input('Enter the number of terms : '))
    output = func1(n)
    # output = func2(n)
    print(output)