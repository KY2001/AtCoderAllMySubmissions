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

N = int(input())
num = list(map(int, input().split()))
dp = [[0] * (20 + 10) for _ in range(N + 10)]
dp[0][0] = 1
for i in range(1, N):
    for j in range(20 + 1):
        if dp[i - 1][j] != 0:
            if 0 <= j - num[i - 1] <= 20:
                dp[i][j - num[i - 1]] += dp[i - 1][j]
            if 0 <= j + num[i - 1] <= 20:
                dp[i][j + num[i - 1]] += dp[i - 1][j]
print(dp[N-1][num[-1]])