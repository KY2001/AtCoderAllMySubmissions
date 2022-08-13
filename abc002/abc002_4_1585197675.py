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
INF = 10 ** 18
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

N, M = map(int, input().split())

friend = [[0] * N for _ in range(N)]

for _ in range(M):
    x, y = map(int, input().split())
    friend[x - 1][y - 1] = 1
    friend[y - 1][x - 1] = 1
ans = 0
for i in range(2 ** N):
    people = []
    p = 1
    for j in range(N):
        if (i >> j) & 1:
            people.append(j)
    for j in itertools.combinations(people, 2):
        if not friend[j[0]][j[1]]:
            p = 0
            break
    if p:
        ans = max(ans, len(people))
print(ans)
