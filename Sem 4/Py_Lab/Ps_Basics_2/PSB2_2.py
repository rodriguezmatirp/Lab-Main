if __name__ == '__main__' :
    sentence = input('Enter the list : ')
    num_list = list(sentence.split())
    num = input('Enter the element to remove : ')
    num_list.remove(num)
    print(num_list)
