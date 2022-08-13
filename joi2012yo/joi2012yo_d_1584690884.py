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

MOD = 10 ** 4
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

N, K = map(int, input().split())
AB = sorted([list(map(int, input().split())) for _ in range(K)])
check = [-1] * (N + 1)
for i in AB:
    check[i[0]] = i[1] - 1
dp = [[[0] * 2 for _ in range(3)] for _ in range(N + 10)]
if check[1] == -1:
    for i in range(3):
        dp[1][i][0] = 1
else:
    dp[1][check[1]][0] = 1
for i in range(1, N):
    if check[i+1] == -1:
        for j in range(3):
            for l in range(2):
                dp[i][j][l] %= MOD
            for l in range(3):
                if j != l:
                    dp[i+1][l][0] += sum(dp[i][j])
            dp[i+1][j][1] += dp[i][j][0]
    else:
        food = check[i+1]
        for j in range(3):
            for l in range(2):
                dp[i][j][l] %= MOD
            if j != food:
                dp[i+1][food][0] += sum(dp[i][j])
        dp[i+1][food][1] += dp[i][food][0]
print(sum([sum(dp[N][i]) for i in range(3)]) % MOD)

