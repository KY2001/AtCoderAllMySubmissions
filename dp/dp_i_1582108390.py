import sys
import math
from collections import deque
import copy
from decimal import *

N = int(input())
p = list(map(float, input().split()))
for i in range(N):
    p[i] = Decimal(str(p[i]))
if N == 1:
    print(p[0])
    sys.exit()
dp = [[Decimal("0") for _ in range(N + 10)] for _ in range(N + 10)]
dp[2][0] = (Decimal("1") - p[0]) * (Decimal("1") - p[1])
dp[2][2] = p[0] * p[1]
dp[2][1] = Decimal("1") - dp[2][0] - dp[2][2]
for i in range(3, N + 1):
    dp[i][0] = dp[i - 1][0] * p[i - 1]
for i in range(3, N + 1):
    for l in range(1, N + 1):
        dp[i][l] = dp[i - 1][l] * (Decimal("1") - p[i - 1]) + dp[i - 1][l - 1] * p[i - 1]
ans = Decimal("0")
for i in range(N // 2 + 1, N + 1):
    ans += dp[N][i]
print(ans)
