import numpy as np

def inverse(list):
    x = np.array(list)
    y = np.linalg.inv(x)
    return y

print(inverse([[1,2],[2,1]]))
print(inverse([[1, 2,1], [2, 1,0],[0,3,1]]))
