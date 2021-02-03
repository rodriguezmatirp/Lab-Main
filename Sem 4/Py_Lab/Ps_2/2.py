import math
def euclideanDistance(u,v):
    n = len(u)
    result = 0
    for x in range(n):
        result += abs(u[x] - v[x])**2
    return math.sqrt(result)

if __name__ == "__main__":
    print(euclideanDistance([0,3,6],[4,0,6]))