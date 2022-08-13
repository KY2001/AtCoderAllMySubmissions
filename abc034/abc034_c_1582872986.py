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

W, H = map(int, input().split())
ans = 0


def nck(n, k, mod):
    """
     O(n)でnCkを返す関数。
    """

    def continuous_inv(n, mod):
        """
        O(n)で1からnまでの範囲の逆元のリストを返す。
        """
        inv_list = [1]  # 0で割るというのは定義されないので無視。
        for i in range(n):
            inv_list.append(int(mod - inv_list[(mod % (i + 2)) - 1] * (mod // (i + 2)) % mod))
        return inv_list

    inv_list = continuous_inv(max(k, n - k), mod)
    return_value = 1
    for i in range(2, n + 1):
        return_value *= i
        return_value %= mod
    for i in range(k):
        return_value *= inv_list[i]
        return_value %= mod
    for i in range(n - k):
        return_value *= inv_list[i]
        return_value %= mod
    return return_value


print(nck(W + H - 2, W - 1, MOD))
