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
import bisect

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

N = int(input())
a = list(map(int, input().split()))
dp = [INF for _ in range(N+10)]

for i in a:
    ind = bisect.bisect(dp, i)
    if dp[ind] > i:
        dp[ind] = i

print(bisect.bisect_left(dp, INF))
