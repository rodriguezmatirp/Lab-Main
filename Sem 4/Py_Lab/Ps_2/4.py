import math

def pythagorean_triples(n):
    triples_list = []
    for x in range(n):
        for y in range(1,x):
            z = math.sqrt(x**2 + y**2)
            if z % 1 == 0:
                triples_list.append([x,y,int(z)])
    return triples_list

print(pythagorean_triples(100))