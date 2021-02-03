import numpy as np

def isSymmetric(matrix):
    matrix = np.array(matrix)
    if matrix.T.all() == matrix.all():
        return True
    return False

def isStocastic(matrix):
    matrix = np.array(matrix)
    for x in matrix:
        if float(sum(x)) == 1.0 :
            if all(0 <= y <= 1.0 for y in x) is False:
                return False
        else:
            return False
    return True

def identity(matrix):
    n = len(matrix)
    matrix = np.array(matrix)
    # print(np.allclose(np.identity(n), matrix))
    return np.allclose(np.identity(n),matrix)

def orthogonal(matrix):
    matrix = np.array(matrix)
    res1 = np.dot(matrix,matrix.T)
    res2 = np.dot(matrix.T, matrix)
    # print(matrix,matrix.T)
    if identity(res1) and identity(res2):
        return True
    return False

print(isStocastic([[1,0],[0.6,0.4]]))
print(isSymmetric([[2, 3, 4], [3, 45, 8], [4, 8, 78]]))
print(orthogonal([[1/3,2/3,-2/3],[-2/3,2/3,1/3],[2/3,1/3,2/3]]))
