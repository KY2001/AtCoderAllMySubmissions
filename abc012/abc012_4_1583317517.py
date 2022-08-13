import sys
import math
import fractions
import itertools
from collections import deque
import copy
import heapq
import bisect
from scipy.sparse.csgraph import shortest_path
import numpy as np

MOD = float('inf')
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N, M = map(int, input().split())
a = [0 for _ in range(M)]
b = [0 for _ in range(M)]
t = [0 for _ in range(M)]
for i in range(M):
    a[i], b[i], t[i] = map(int, input().split())
info = np.array([[0 for _ in range(N)] for _ in range(N)])

for p, q, r in zip(a, b, t):
    info[p - 1][q - 1] = r
    info[q - 1][p - 1] = r

result = shortest_path(info)
ans = [max(result[i]) for i in range(N)]
print(int(min(ans)))
