import sys
import math
import string
import fractions
import random
from operator import itemgetter
import itertools
from collections import deque
import copy
import heapq
from bisect import bisect, bisect_left, bisect_right

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)


def comb2(a):
    if a % 2 == 0:
        return (a // 2) * (a - 1)
    else:
        return ((a - 1) // 2) * a


N = int(input())
A = list(map(int, input().split()))
if A[0] != 0:
    print(0)
    sys.exit()
A.sort()
A = A[1:]
num = [0 for _ in range(N + 10)]
if 0 in A:
    print(0)
    sys.exit()
else:
    for i in A:
        num[i - 1] += 1
    for i in range(N - 1):
        if num[i] == 0 and num[i + 1] != 0:
            print(0)
            sys.exit()
    ans = 1
    for i in range(N):
        ans *= pow(2, comb2(num[i]), MOD)
        ans %= MOD
        p = max(1, pow(2, num[i]) - 1) % MOD
        for j in range(num[i + 1]):
            ans *= p
            ans %= MOD
print(ans)
