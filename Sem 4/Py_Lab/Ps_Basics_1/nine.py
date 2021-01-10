if __name__ == '__main__':
    array = []
    length = int(input('Length : '))
    print('Enter the elements : ')
    for x in range(length):
        elem = array.append(input())    
    cen_mean = (sum(array) - min(array) - min(array))/(length -2) 
    print(f'Centered Mean : {cen_mean}')    
    
