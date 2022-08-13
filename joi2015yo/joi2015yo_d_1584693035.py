import sys
import math
import string
import collections
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

N, M = map(int, input().split())
D = [int(input()) for _ in range(N)]
C = [int(input()) for _ in range(M)]

dp = [INF] * (N + 10)
dp[0] = 0
for i in range(M):
    c = C[i]
    for l in range(N, 0, -1):
        dp[l] = min(dp[l - 1] + D[l - 1] * c, dp[l])
print(dp[N])
