if(__name__ == '__main__'):
    n = int(input('Enter the number of links : '))
    print('Enter the list :')
    link_list = []
    for x in range(n):
        elem = input()
        link_list.append(elem)
        suff = elem.split('.')[2]
        print(f'{suff} - {elem}')
    