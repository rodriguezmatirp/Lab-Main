def isPrime(num):
    num = int(num)
    if num > 1:
        for i in range(2,int(num/2 + 1)):
            if num % i == 0:
                return False
    return True

if(__name__ == '__main__'):
    prime = []
    for x in range(1,50):
        if(isPrime(x)) : 
            prime.append(x)
    print(prime)