import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect
from scipy.sparse.csgraph import dijkstra
from scipy.sparse import csr_matrix, lil_matrix, coo_matrix

MOD = float('inf')
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N, M, K, S = map(int, input().split())
P, Q = map(int, input().split())
C = [int(input()) for _ in range(K)]
AB = [list(map(int, input().split())) for _ in range(M)]
info2 = [[] for _ in range(N + 1)]
check = [0 for _ in range(N + 1)]
dangerous_towns = [0 for _ in range(N + 1)]
for i in AB:
    info2[i[0] - 1].append([i[1] - 1, 1])
    info2[i[1] - 1].append([i[0] - 1, 1])
for i in C:
    info2[N].append([i - 1, 1])
data = []
row = []
column = []
for i in range(N):
    data.append(0)
    row.append(i)
    column.append(i)

pos = [[N, 0]]
while len(pos) > 0:

    index, depth = pos.pop(0)

    check[index] = 1
    if depth <= S + 1:
        dangerous_towns[index] = 1
        for i in info2[index]:
            if check[i[0]] == 0:
                pos.append([i[0], depth + 1])

for i in C:
    dangerous_towns[i - 1] = 2
for i in AB:
    if i[1] - 1 == N - 1:
        data.append(10 ** -9)
        row.append(i[0] - 1)
        column.append(i[1] - 1)
    else:
        if dangerous_towns[i[1] - 1] == 0:
            data.append(P)
            row.append(i[0] - 1)
            column.append(i[1] - 1)
        elif dangerous_towns[i[1] - 1] == 1:
            data.append(Q)
            row.append(i[0] - 1)
            column.append(i[1] - 1)
    if i[0] - 1 == N - 1:
        data.append(10 ** -9)
        row.append(i[1] - 1)
        column.append(i[0] - 1)
    else:
        if dangerous_towns[i[0] - 1] == 0:
            data.append(P)
            row.append(i[1] - 1)
            column.append(i[0] - 1)
        elif dangerous_towns[i[0] - 1] == 1:
            data.append(Q)
            row.append(i[1] - 1)
            column.append(i[0] - 1)

print(int(dijkstra(coo_matrix((data, (row, column)), shape=(N, N)).tocsr(), indices=0)[N - 1]))
