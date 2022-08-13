import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect
import heapq
import numpy as np
from scipy.sparse.csgraph import bellman_ford

MOD = float('inf')
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

n, k = map(int, input().split())
info = np.full((n, n), INF)
for i in range(n):
    info[i][i] = 0
for _ in range(k):
    query = list(map(int, input().split()))
    if query[0] == 0:
        ans = bellman_ford(info, indices=query[2]-1)
        if ans[query[1] - 1] != INF:
            print(int(ans[query[1] - 1]))
        else:
            print(-1)
    else:
        info[query[1] - 1][query[2] - 1] = min(query[3], info[query[1] - 1][query[2] - 1])
        info[query[2] - 1][query[1] - 1] = min(query[3], info[query[2] - 1][query[1] - 1])
