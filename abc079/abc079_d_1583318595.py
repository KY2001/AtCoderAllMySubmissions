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

H, W = map(int, input().split())
c = [list(map(int, input().split())) for _ in range(10)]
A = [list(map(int, input().split())) for _ in range(H)]

result = shortest_path(np.array(c))

ans = 0
for i in range(H):
    for l in range(W):
        if A[i][l] != -1:
            ans += result[A[i][l]][1]
print(int(ans))


