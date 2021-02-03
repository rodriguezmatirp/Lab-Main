import math

def dotProduct(v,u):
    result = 0
    for x in range(len(v)):
        result += v[x]*u[x]
    return result

def norm(x):
    return math.sqrt(dotProduct(x,x))

def theta(v,u):
    return math.acos(dotProduct(v,u)/(norm(u)*norm(v)))*180/math.pi

def cosine(v,u):
    return dotProduct(v, u)/(norm(u)*norm(v))

print(cosine([0,3],[4,0]))

#Need to compare with Euclidean Distance