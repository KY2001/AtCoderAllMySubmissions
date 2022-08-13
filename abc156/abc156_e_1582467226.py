import sys
import math
import itertools
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

n, k = map(int, input().split())

inv_list = [1]  # 0で割るというのは定義されないので無視。
for i in range(n):
    inv_list.append(int(MOD - inv_list[(MOD % (i + 2)) - 1] * (MOD // (i + 2)) % MOD))
if k >= n:
    ans = 1
    for i in range(2 * n - 1):
        ans *= (i + 1)
        ans %= MOD
    for i in range(n):
        ans *= inv_list[i]
        ans *= inv_list[i]
        ans %= MOD
    ans *= n
    ans %= MOD
    print(ans)
else:
    ans = 1
    nCm = 1
    nmHm = 1
    for i in range(k):
        nCm *= n - i
        nCm *= inv_list[i]
        nCm %= MOD
        nmHm *= (n - 1) - i
        nmHm *= inv_list[i]
        nmHm %= MOD
        ans += nCm * nmHm
        ans %= MOD
    print(ans)
