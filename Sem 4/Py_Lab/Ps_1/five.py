def most_popular(friends):
    result = {}
    for x in friends :
        person = friends.get(x)
        for y in person:
            if y in result:
                result[y].append(person[y])
            else:
                result[y] = [person[y]]
    min_value = 100
    popular = ''
    for x in result:
        result[x] = sum(result[x])/len(result[x])
        if min_value > result[x]:
            popular = x
            min_value = result[x]

    return popular

alice_ratings = {"alonzo": 1, "bob": 3, "turing" : 2}
bob_ratings = {"alice": 1, "alonzo": 2, "turing": 3}
alonzo_ratings = {"alice": 3, "bob": 2, "turing": 1}
turing_ratings = {"alice": 2, "alonzo": 1, "bob": 3}
friends = {"alice": alice_ratings, "bob": bob_ratings, 
"alonzo": alonzo_ratings,"turing": turing_ratings}
print(most_popular(friends))