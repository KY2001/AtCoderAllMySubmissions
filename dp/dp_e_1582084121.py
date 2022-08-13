import sys
import math
from collections import deque
import copy

N, W = map(int, input().split())
wv = [list(map(int, input().split())) for _ in range(N)]
INF = 10 ** 9 + 7
dp = [[INF for _ in range(N * 300 + 1)] for _ in range(N + 1)]

for i in dp:
    i[0] = 0
for i in range(1, wv[0][1]+1):
    dp[1][i] = wv[0][0]

for i in range(2, N + 1):
    for l in range(1, N * 300 + 1):
        if l - wv[i - 1][1] >= 0:
            dp[i][l] = min(dp[i - 1][l], dp[i - 1][l - wv[i - 1][1]] + wv[i - 1][0])
        elif dp[i][l] == 10**9+7:
            dp[i][l] = min(wv[i-1][0], dp[i-1][l])
        else:
            dp[i][l] = dp[i - 1][l]
for i, l in enumerate(dp[-1]):
    if l <= W < dp[-1][i + 1]:
        print(i)
        break

