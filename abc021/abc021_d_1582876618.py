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

n = int(input())
k = int(input())
ans = 0


def continuous_inv(n, mod):
    """
    1からnまでの範囲の逆元のリストを返す。
    """
    inv_list = [1]  # 0で割るというのは定義されないので無視。
    for i in range(n):
        inv_list.append(int(mod - inv_list[(mod % (i + 2)) - 1] * (mod // (i + 2)) % mod))
    return inv_list


inv_list = continuous_inv(max(n - 1, k + 2), MOD)
ans = 1
for i in range(n + k - 1):
    ans *= (i + 1)
    ans %= MOD
for i in range(n - 1):
    ans *= inv_list[i]
    ans %= MOD
for i in range(k):
    ans *= inv_list[i]
    ans %= MOD
print(ans)
