import sys
import math
from collections import deque

N, K = map(int, input().split())
h = list(map(int, input().split()))

dp = [[10**9 for _ in range(K+1)] for _ in range(N)]
dp[0] = [0 for _ in range(K+1)]

for i in range(N):
    for l in range(K):
        if i-(l+1) >= 0:
            dp[i][l] = dp[i - (l + 1)][K] + abs(h[i] - h[i - (l + 1)])
        else:
            dp[i][l] = min(dp[i])
        if l == K-1:
            dp[i][K] = min(dp[i])
print(min(dp[N-1]))