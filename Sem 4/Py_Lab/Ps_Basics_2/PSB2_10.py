if __name__ == "__main__":
    lines = []
    input_sentence = input("Please enter the sentence: ")
    lines = input_sentence.split(". ")
    sentences = []
    for line in lines:
        words = line.split(':')[1].split()
        sentences.append([line.split(":")[0],words.sort()])
    print(sentences)