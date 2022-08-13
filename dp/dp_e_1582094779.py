import sys
import math
from collections import deque
import copy

INF = 10 ** 9 + 7
N, W = map(int, input().split())
weight = []
value = []
for i in range(N):
    tempW, tempV = map(int, input().split())
    weight.append(tempW)
    value.append(tempV)

dp = [[INF for _ in range(N * 300 + 1)] for _ in range(N + 1)]
dp[0][0] = 0

for i in range(1, N + 1):
    for l in range(N * 300 + 1):
        if l - value[i - 1] >= 0:
            dp[i][l] = min(dp[i - 1][l], dp[i - 1][l - value[i - 1]] + weight[i - 1])
        else:
            dp[i][l] = dp[i - 1][l]
for i in range(N * 300 + 1):
    if dp[N][i] <= W:
        ans = i
print(ans)
