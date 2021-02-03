def digits(x):
    if int(x) <= 0:
        return 0
    else:
        return digits(x/10) + 1

print(digits(2190))