import math
def abs_(x):
    if isinstance(x,complex):
        x = complex(x)
        return math.sqrt(x.real**2+ x.imag**2)
    if x >= 0:
        return x
    else:
        return -x

print(abs_(4-5j))