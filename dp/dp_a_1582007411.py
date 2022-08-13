import sys
import math
from collections import deque

N = int(input())
h = list(map(int, input().split()))

dp = [[-1, -1] for _ in range(N)]
dp[0] = [0, 0]
dp[1] = [abs(h[0]-h[1]), abs(h[0]-h[1])]
for i in range(2, N):
    dp[i][0] = min(dp[i - 1]) + abs(h[i] - h[i - 1])
    dp[i][1] = min(dp[i - 2]) + abs(h[i] - h[i - 2])

print(min(dp[N-1]))
