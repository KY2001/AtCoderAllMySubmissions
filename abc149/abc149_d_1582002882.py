import sys
import math
from collections import deque
import copy

N, K = map(int, input().split())
R, S, P = map(int, input().split())
T = list(input())

SUM = 0

for i in range(1, K + 1):
    p = 0
    t = []
    for l in range(10 ** 9):
        t.append(T[i + K * l - 1])
        if (i + K * (l + 1) -1 ) >= N:
            break
    dp = [[-1, -1, -1] for _ in range(len(t) + 1)]
    dp[0] = [0, 0, 0]
    for l in range(1, len(t) + 1):
        if t[l - 1] == "r":
            dp[l][0] = max(dp[l - 1][1], dp[l - 1][2])
            dp[l][1] = max(dp[l - 1][0], dp[l - 1][2])
            dp[l][2] = max(dp[l - 1][0], dp[l - 1][1]) + P
        elif t[l - 1] == "s":
            dp[l][0] = max(dp[l - 1][1], dp[l - 1][2]) + R
            dp[l][1] = max(dp[l - 1][0], dp[l - 1][2])
            dp[l][2] = max(dp[l - 1][0], dp[l - 1][1])
        else:
            dp[l][0] = max(dp[l - 1][1], dp[l - 1][2])
            dp[l][1] = max(dp[l - 1][0], dp[l - 1][2]) + S
            dp[l][2] = max(dp[l - 1][0], dp[l - 1][1])
    SUM += max(dp[len(t)])
print(SUM)
