import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect
import numpy

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

P = float(input())
t = -10
if P <= 1.5:
    print(P)
    sys.exit()

def dividing_search(left, right):
    """
    2分探索
    """
    middle = ((left + right) // 2)
    a = middle * 10 ** t + P / (2 ** (middle * 10 ** t / 1.5))
    b = (middle - 1) * 10 ** t + P / (2 ** ((middle - 1) * 10 ** t / 1.5))
    c = (middle + 1) * 10 ** t + P / (2 ** ((middle + 1) * 10 ** t / 1.5))
    if a <= b and a <= c:
        print(a)
    elif c < b and c < a:
        dividing_search((left + right) // 2, right)
    elif left == right:
        print(a)
    else:
        dividing_search(left, (left + right) // 2)


c = 10 ** 12
dividing_search(0, c)
