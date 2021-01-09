import random,string

def password_generator(length):
    password = ''
    for x in range(4) : 
        password = password+ random.choice(string.ascii_uppercase) + random.choice(string.ascii_lowercase) + random.choice(string.digits) + random.choice(string.punctuation)
    # for y in range(int(length) - 4):
        # password = password + random.choice(string.ascii_uppercase + string.ascii_lowercase + string.digits + string.punctuation)
    return password[:int(length)]

if __name__ == '__main__':
    length = input('Enter password length : ')
    new_pass = password_generator(length)
    print(new_pass)
