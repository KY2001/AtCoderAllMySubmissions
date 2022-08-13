import sys
import math
from collections import deque
import copy
import bisect

INF = 10 ** 9 + 7

N = int(input())
a = list(map(int, input().split()))

dp = [INF for _ in range(N + 10)]

for i in range(N):
    index = bisect.bisect_left(dp, a[i])
    dp[index] = a[i]
print(bisect.bisect_left(dp, INF))
