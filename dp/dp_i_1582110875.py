import sys
import math
from collections import deque
import copy

N = int(input())
p = list(map(float, input().split()))
if N == 1:
    print(p[0])
    sys.exit()
dp = [[0 for _ in range(N + 10)] for _ in range(N + 10)]
dp[2][0] = (1.0 - p[0]) * (1.0 - p[1])
dp[2][2] = p[0] * p[1]
dp[2][1] = 1.0 - dp[2][0] - dp[2][2]
for i in range(3, N + 1):
    for l in range(1, N + 1):
        dp[i][l] = dp[i - 1][l] * (1.0 - p[i - 1]) + dp[i - 1][l - 1] * p[i - 1]
ans = 0.0
for i in range(N // 2 + 1, N + 1):
    ans += dp[N][i]
print(math.ceil(ans*10**10)/10**10)
