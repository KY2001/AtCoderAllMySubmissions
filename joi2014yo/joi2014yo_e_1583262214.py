import sys
import math
import fractions
import itertools
from collections import deque
import copy
import heapq
import bisect
from scipy.sparse.csgraph import shortest_path, dijkstra
from scipy.sparse import csr_matrix, coo_matrix
import numpy as np

MOD = float('inf')
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N, K = map(int, input().split())
CR = [list(map(int, input().split())) for _ in range(N)]
AB = [list(map(int, input().split())) for _ in range(K)]

data = [1 for _ in range(len(AB))]
row = []
column = []
for i in AB:
    row.append(i[0] - 1)
    column.append(i[1] - 1)

result = shortest_path(coo_matrix((data, (row, column)), shape=(N, N)).tocsr(), directed=False)

info = np.zeros((N, N), np.int32)
for i in range(N):
    for l in range(N):
        if result[i][l] <= CR[i][1]:
            info[i][l] = CR[i][0]

print(int(dijkstra(info, indices=0)[N-1]))

