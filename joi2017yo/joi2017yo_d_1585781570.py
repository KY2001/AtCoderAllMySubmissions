#!usr/bin/env python3
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
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

N, M = map(int, input().split())
dolls = [int(input()) - 1 for _ in range(N)]
dolls_cum_sum = list(itertools.accumulate(dolls)) + [0]
dolls_cum_sum_each = []
for i in range(M):
    dolls_cum_sum_each.append(list(itertools.accumulate([1 if dolls[j] == i else 0 for j in range(N)])) + [0])
dp = [INF] * (2 ** M + 10)
sum_list = [INF] * 2 ** M
for i in range(2 ** M):
    Sum = 0
    for j in range(M):
        if i & (1 << j):
            Sum += dolls_cum_sum_each[j][-2]
    sum_list[i] = Sum
dp[0] = 0

for i in range(2 ** M):
    for j in range(M):
        if not i & (1 << j):
            dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + dolls_cum_sum_each[j][sum_list[i] - 1] + (
                    dolls_cum_sum_each[j][-2] - dolls_cum_sum_each[j][sum_list[i] + dolls_cum_sum_each[j][-2] - 1]))
print(dp[2 ** M - 1])