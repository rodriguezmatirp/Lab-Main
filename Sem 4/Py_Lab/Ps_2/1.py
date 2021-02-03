divFive = lambda num: num % 5 == 0
divThree = lambda num: num % 3 == 0
if __name__ == "__main__":
    for x in range(1,101):
        if divFive(x) and divThree(x):
            print(f'FizzBuzz - {x}')
        else:
            if divFive(x):
                print(f'Buzz - {x}')
            elif divThree(x):
                print(f'Fizz - {x}')