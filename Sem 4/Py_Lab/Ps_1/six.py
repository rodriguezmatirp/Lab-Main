def metathesis_pair(word_1,word_2):
    char_list_1 = []
    char_list_2 = []
    if len(word_1) != len(word_2):
        return False
    for x in range(len(word_1)):
        if word_1[x] != word_2[x]:
            char_list_1.append(word_1[x])
            char_list_2.append(word_2[x])
    print(char_list_1)
    print(char_list_2)
    if len(char_list_2) == len(char_list_1) and len(char_list_1) ==2 and set(char_list_1) == set(char_list_2):
        return True
    return False

print(metathesis_pair('converse','conserve'))