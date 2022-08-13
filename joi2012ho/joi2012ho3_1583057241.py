import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N, T, S = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(N)]

dp = [[0 for _ in range(T + 10)] for _ in range(N + 10)]
for i in range(AB[0][1] - 1, T):
    if i - AB[0][1] + 1 < S - 1 < i:
        dp[0][i] = 0
    else:
        dp[0][i] = AB[0][0]
for i in range(1, N):
    for l in range(T):
        if l - AB[i][1] >= 0:
            if l - AB[i][1] + 1 < S - 1 < l:
                dp[i][l] = dp[i - 1][l]
            else:
                dp[i][l] = max(dp[i - 1][l], dp[i - 1][l - AB[i][1]] + AB[i][0])
        else:
            dp[i][l] = dp[i - 1][l]
print(dp[N - 1][T - 1])
