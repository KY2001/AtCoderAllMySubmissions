import sys
import math
from collections import deque
import copy

N, W = map(int, input().split())
wv = [list(map(int, input().split())) for _ in range(N)]
INF = 10 ** 9 + 7
dp = [[INF for _ in range(N * 300)] for _ in range(N)]

for i in range(wv[0][1]):
    dp[0][i] = wv[0][0]
for i in range(1, N):
    for l in range(N * 300):
        if l - wv[i - 1][1] >= 0:
            dp[i][l] = min(dp[i - 1][l], dp[i - 1][l - wv[i][1]] + wv[i][0])
        else:
            dp[i][l] = min(dp[i - 1][l], wv[i][0])
for i in range(N * 300 - 1):
    if dp[-1][i] <= W < dp[-1][i + 1]:
        print(i+1)
        break
