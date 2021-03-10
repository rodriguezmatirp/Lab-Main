import re

def convert_gx(gx):
    data =[]
    for x in re.findall(r"x\*\*\d+",gx):
        data.append(x[-1])
    result = ['0']*(int(max(data))+1)
    for x in range(int(max(data))+1):
        if str(x) in data:
            result[x] = '1'
    result.reverse()
    return ''.join(result)

def find_remainder(data,key):
    inc = len(key)
    tmp = list(data[0:inc])
    data = list(data)
    while inc < len(data):
        if tmp[0] == '1':
            for x in range(len(key)):
                if x == len(key) -1:
                    tmp[x] = data[inc]
                else:
                    tmp[x] = str(int(tmp[x+1]) ^ int(key[x+1]))
        else :
            for x in range(len(key)):
                if x == len(key) -1:
                    tmp[x] = data[inc]
                else:
                    tmp[x] = tmp[x+1]
        inc += 1
    return ''.join(tmp)

def encode(data,key):
    appended = data + '0'*len(key)
    remainder = find_remainder(appended,key)

    return data + remainder

def decode(data,key):
    appended = data + '0'*len(key)
    remainder = find_remainder(appended, key)

    return remainder

# print(decode('101101','1010'))