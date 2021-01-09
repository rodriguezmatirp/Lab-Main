def base_freq(string):
    frequency = {}
    for x in string:
        if x in frequency:
            frequency[x] += 1
        else:
            frequency[x] = 1
    return frequency


print(base_freq("AAGTTAGTCA"))