def delete_consonants(string):
    vowels = ['a','e','i','o','u']
    result = [x for x in string if x.lower() in vowels]
    return "".join(result)

if __name__ == '__main__':
    user_input = input('Enter the string : ')
    print(delete_consonants(user_input))