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

N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]

result, path = shortest_path(np.array(A), return_predecessors=True)
ans = 0
for i in range(N):
    for l in range(N):
        if result[i][l] != A[i][l]:
            print(-1)
            sys.exit()
        ans += A[i][l]
        if A[i][l] == 0:
            A[i][l] = INF

ans /= 2
for i in range(N - 1):
    for l in range(i + 1, N):
        for k in range(N):
            if A[i][l] == A[i][k] + A[k][l]:
                ans -= A[i][l]
                break
print(int(ans))
