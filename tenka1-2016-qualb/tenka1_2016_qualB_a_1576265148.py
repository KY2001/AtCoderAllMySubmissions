import math


def abc(n):
    return math.ceil((n**2+4)/8)


print(abc(abc(abc(20))))