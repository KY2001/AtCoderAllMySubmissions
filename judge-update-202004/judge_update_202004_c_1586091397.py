#!usr/bin/env python3
import sys
import math
import string
import collections
import fractions
import random
from operator import itemgetter
import itertools
from collections import deque
import copy
import heapq
import bisect

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

a = list(map(int, input().split()))
ans = 0
check = itertools.permutations([i for i in range(1, sum(a) + 1)], sum(a))
for i in check:
    a1 = [i[j] for j in range(a[0])]
    a2 = [i[j] for j in range(a[0], a[0] + a[1])]
    a3 = [i[j] for j in range(a[0] + a[1], sum(a))]
    aa = [a1, a2, a3]
    p = 1
    for j in range(3):
        for k in range(1, a[j]):
            if aa[j][k] <= aa[j][k - 1]:
                p = 0
                break
    for j in range(1, 3):
        for k in range(a[j]):
            if aa[j][k] <= aa[j - 1][k]:
                p = 0
                break
    if p:
        ans += 1
print(ans)