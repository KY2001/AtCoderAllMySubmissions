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

MOD = 10 ** 4 + 7
INF = 10 ** 18
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

N = int(input())
S = list(input())
for i in range(N):
    if S[i] == "J":
        S[i] = 0
    elif S[i] == "O":
        S[i] = 1
    else:
        S[i] = 2
dp = [[0] * (2 ** 3 + 1) for _ in range(N + 1)]
for i in range(2 ** 3):
    if i & 1 and i & (1 << S[0]):
        dp[0][i] += 1
for i in range(N - 1):
    for j in range(2 ** 3):
        if j & (1 << S[i + 1]):
            for k in range(2 ** 3):
                if k & (1 << S[i + 1]):
                    dp[i + 1][k] += dp[i][j] % MOD
        else:
            for k in range(2 ** 3):
                if k & (1 << S[i + 1]) and k & j:
                    dp[i + 1][k] += dp[i][j] % MOD
print(sum(dp[N - 1]) % MOD)