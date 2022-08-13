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
keys = []
for _ in range(M):
    a, b = map(int, input().split())
    bits = sum([1 << (i - 1) for i in map(int, input().split())])
    keys.append([a, bits])

dp = [INF] * (2 ** N + 10)
dp[0] = 0

for i in range(M):
    for j in range(2 ** N):
        dp[j|keys[i][1]] = min(dp[j|keys[i][1]], dp[j]+keys[i][0])
print(dp[2 ** N - 1] if dp[2 ** N - 1] != INF else -1)