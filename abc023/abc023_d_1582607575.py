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

N = int(input())
HS = [list(map(int, input().split())) for _ in range(N)]


def true_or_false(a):
    p = []
    for hs in HS:
        p.append(math.floor((a - hs[0]) / hs[1]) + 1)
    p.sort()
    for i in range(N):
        if p[i] < i + 1:
            return False
    return True


def divide_search(a, b):
    c = (a + b) // 2
    B = true_or_false(c + 1)
    B2 = true_or_false(c)
    if B is True and B2 is False:
        return c + 1
    elif B is False:
        return divide_search(c, b)
    else:
        return divide_search(a, c)


print(divide_search(1, 10 ** 19))
