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

N, M, V, P = map(int, input().split())
A = sorted(list(map(int, input().split())), reverse=True)
ans = P
if V <= P:
    for i in A[P:]:
        if i + M >= A[P-1]:
            ans += 1
else:
    cum_sum = list(itertools.accumulate(A))
    for i in range(P, N):
        enemy = i - (P - 1)
        val = math.ceil((cum_sum[i - 1] - cum_sum[P - 2] + max(0, M * (V - (N - enemy)))) / enemy)
        if A[i] + M >= val:
            ans += 1
print(ans)
