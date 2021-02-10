if __name__ == "__main__":
    input_sentence = input("Please enter the sentence: ")
    lines = input_sentence.split(". ")
    sentences = []
    word_list = []
    for line in lines:
        words = line.split(':')[1].split()
        sentences.append([line.split(":")[0],words])
        for word in words:
            if word not in word_list:
                word_list.append(word)
    word_list.sort()
    # print(sentences)
    # print(word_list)

    result = {x:[] for x in word_list }
    for x in word_list:
        for y in sentences:
            if x in y[1]:
                result[x].append(y[0])

    print(result)
