sequence = [3, 6, 9, 12, 15, 21, 24]
a = sequence
mid = int(len(a)/2)
b = a
c = a[mid : mid + 2]
del a[mid:mid+2]
print(a)
a = a[:mid] + c + a[mid:]
print(a)