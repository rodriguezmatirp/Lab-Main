import itertools

def metathesis_pair(word_1,word_2):
    char_list_1 = []
    char_list_2 = []
    if len(word_1) != len(word_2):
        return False
    for x in range(len(word_1)):
        if word_1[x] != word_2[x]:
            char_list_1.append(word_1[x])
            char_list_2.append(word_2[x])
    if len(char_list_2) == len(char_list_1) and len(char_list_1) ==2 and set(char_list_1) == set(char_list_2):
        return True
    return False

def dictionary(input_list):
    result = []
    pairs = list(itertools.combinations(input_list,2))        
    for x,y in pairs:
        if len(x) == len(y):
            if metathesis_pair(x,y):
                result.append((x,y))
    return result

if __name__ == "__main__":
    input_list = []
    length = int(input('Enter the number of words : '))
    print('Enter the words : ')
    for x in range(length):
        word = input(f'{x+1} : ')
        input_list.append(word)
    result = dictionary(input_list)
    print(result)
# print(metathesis_pair('converse','conserve'))