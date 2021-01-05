count = 0

for i in range(2000,3201):
    if i%7 == 0 and i%5 != 0 :
        count += 1
        print(i,',')

if count == 0:
    print('None!')
else:
    print(f'total count - {count}')