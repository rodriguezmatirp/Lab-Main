if __name__ == '__main__':
    sentence = input('Enter the sentence : ')
    words = [word.lower() for word in sentence.split()]
    words.sort()
    unique_sorted = []
    for word in words:
        if not word in unique_sorted : 
            unique_sorted.append(word)
    print(unique_sorted)