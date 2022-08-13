import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N = int(input())
HS = [list(map(int, input().split())) for _ in range(N)]
c = [0 for _ in range(10 ** 5 + 1)]


def bucket_sort(p):
    ans = []
    for i in p:
        c[i] += 1
    for i in range(10 ** 5 + 1):
        if c[i] != 0:
            for l in range(c[i]):
                ans.append(i)
            c[i] = 0
    return ans


def true_or_false(a):
    p = [0 for _ in range(N)]
    for i, hs in enumerate(HS):
        p[i] = max(0, min(10 ** 5, math.floor((a - hs[0]) / hs[1]) + 1))
    p = bucket_sort(p)
    for i, num in enumerate(p):
        if num < i + 1:
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


print(divide_search(1, 10 ** 19 + 1))
