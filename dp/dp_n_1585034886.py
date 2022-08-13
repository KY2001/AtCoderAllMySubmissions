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
from bisect import bisect, bisect_left, bisect_right

MOD = 10 ** 9 + 7
INF = 10 ** 18
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

N = int(input())
a = list(map(int, input().split()))

dp = [[INF] * (N + 10) for _ in range(N + 10)]
dp2 = [[0] * (N + 10) for _ in range(N + 10)]

for l in range(N):
    dp[l][l] = a[l]

for i in range(N - 2, -1, -1):
    for j in range(i + 1, N):
        dp2[i][j] = min(dp[i][k] + dp2[k + 1][j] + dp2[i][k] + dp[k + 1][j] for k in range(i, j))
        for val in ([dp[i][k] + dp2[k + 1][j] + dp2[i][k] + dp[k + 1][j], k] for k in range(i, j)):
            if val[0] == dp2[i][j]:
                k = val[1]
        dp[i][j] = dp[i][k] + dp[k + 1][j]
print(dp2[0][N - 1])