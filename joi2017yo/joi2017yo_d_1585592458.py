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
dolls = [int(input()) - 1 for _ in range(N)] + [M+10]*3
ans = 0
dp = [0] * (N + 1)

for i in range(N):
    if dp[i - 1] & (1 << dolls[i]):
        dp[i] = dp[i - 1]
        if dolls[i - 1] == dolls[i]:
            continue
        elif dolls[i] == dolls[i - 2] and dolls[i + 1] == dolls[i - 1]:
            continue
        else:
            ans += 1
    else:
        dp[i] = dp[i - 1] | (1 << (dolls[i]))
print(ans)