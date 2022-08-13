import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect
import numpy

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()
N, Q = map(int, input().split())
a = list(map(int, input().split()))
c = deque(map(int, input().split()))
c.append(1)
c.appendleft(1)


def bpm(x, y, mod):
    """
     Bisection power method : 二分累乗法
     O(log y)でx^(y) mod N を求める。
    """
    ans = 1
    x %= mod
    digit = int((math.log(y, 2) // 1 + 1))  # yの２進数表示の桁数
    for i in range(digit):
        if (y >> i) & 1 == 1:
            ans *= x
            ans %= mod
        x **= 2
        x %= mod
    return ans


dis = []
for i in range(N - 1):
    dis.append(bpm(a[i], a[i + 1], MOD))
sum_dis = deque(numpy.cumsum(dis))
sum_dis.appendleft(0)
ans = 0
for i in range(len(c) - 1):
    ans += abs(sum_dis[c[i] - 1] - sum_dis[c[i + 1] - 1])
    ans %= MOD
print(ans)
