def showcount(n):
    return n

if __name__ == '__main__':
    x = showcount(5)
    print(x)

    count = showcount
    x = count(5)
    print(x)