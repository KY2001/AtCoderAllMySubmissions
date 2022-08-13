import sys
import math
import string
import fractions
import random
from operator import itemgetter
import itertools
from collections import deque
import copy
import heapq
import bisect

sys.setrecursionlimit(10 ** 6)
MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

N, Q = map(int, input().split())
info = [[] for _ in range(N)]
ans = [0 for _ in range(N)]

for _ in range(N - 1):
    a, b = map(int, input().split())
    info[a - 1].append(b - 1)
    info[b - 1].append(a - 1)


def checker(n):
    for i in info[n]:
        if n in info[i]:
            del info[i][info[i].index(n)]
        checker(i)


def plus(n, val):
    ans[n] += val
    for i in info[n]:
        plus(i, val + Query[i])


checker(0)
Query = [0 for _ in range(N)]
for _ in range(Q):
    p, x = map(int, input().split())
    Query[p - 1] += x
plus(0, Query[0])
ans = list(map(str, ans))
print(" ".join(ans))
