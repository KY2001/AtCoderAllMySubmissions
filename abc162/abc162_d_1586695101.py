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

N = int(input())
K = list(input())
a = collections.Counter(K)
ans = 0
R = list(itertools.accumulate([1 if K[i] == "R" else 0 for i in range(N)])) + [0]
G = list(itertools.accumulate([1 if i == "G" else 0 for i in K])) + [0]
B = list(itertools.accumulate([1 if i == "B" else 0 for i in K])) + [0]
for i in range(N):
    if K[i] == "R":
        ans += G[i - 1] * B[i - 1]
    elif K[i] == "G":
        ans += R[i - 1] * B[i - 1]
    else:
        ans += R[i - 1] * G[i - 1]
for k in range(2, N):
    for i in range(0, k):
        j = (k + i) / 2
        if j == (k + i) // 2 and j > i:
            j = int(j)
            if K[k] != K[i] and K[k] != K[j] and K[i] != K[j]:
                ans -= 1
print(ans)
