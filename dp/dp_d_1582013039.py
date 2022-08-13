import sys
import math
from collections import deque
import copy

N, W = map(int, input().split())
wv = [list(map(int, input().split())) for _ in range(N)]

dp = [[-1 for _ in range(W + 1)] for _ in range(N + 1)]
for i in dp:
    i[0] = 0
dp[0] = [0 for _ in range(W + 1)]

for i in range(1, N + 1):
    for l in range(1, W + 1):
        if l - wv[i - 1][0] < 0:
            dp[i][l] = dp[i - 1][l]
        else:
            dp[i][l] = max(dp[i - 1][l], dp[i - 1][l - wv[i - 1][0]] + wv[i - 1][1])
print(dp[N][W])
