import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect

MOD = 10 ** 5
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

n, m = map(int, input().split())
s = [int(input()) for _ in range(n - 1)]
a = [int(input()) for _ in range(m)]
s_sum = list(itertools.accumulate(s))
s_sum.append(0)
ans = 0
k = 0
for i in a:
    ans += abs(s_sum[k + i - 1] - s_sum[k - 1])
    ans %= MOD
    k += i
print(ans)
