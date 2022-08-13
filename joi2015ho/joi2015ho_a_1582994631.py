import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect
import numpy as np

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N, M = map(int, input().split())
P = list(map(int, input().split()))
ABC = [list(map(int, input().split())) for _ in range(N - 1)]

visit_time = [0 for _ in range(N + 2)]
for i in range(1, M):
    if P[i] >= P[i - 1]:
        visit_time[P[i - 1]] += 1
        visit_time[P[i]] -= 1
    else:
        visit_time[P[i - 1]] -= 1
        visit_time[P[i]] += 1
visit_time = list(itertools.accumulate(visit_time))
ans = 0
for i in range(1, N):
    if ABC[i-1][0] * visit_time[i] < ABC[i-1][1] * visit_time[i] + ABC[i-1][2]:
        ans += ABC[i-1][0] * visit_time[i]
    else:
        ans += ABC[i-1][1] * visit_time[i] + ABC[i-1][2]
print(ans)
