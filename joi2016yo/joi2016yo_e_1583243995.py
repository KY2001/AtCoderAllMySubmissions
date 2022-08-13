import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect
from scipy.sparse.csgraph import dijkstra
from scipy.sparse import csr_matrix, lil_matrix

MOD = float('inf')
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N, M, K, S = map(int, input().split())
P, Q = map(int, input().split())
C = [int(input()) for _ in range(K)]
AB = [list(map(int, input().split())) for _ in range(M)]
info = [[] for _ in range(N)]
info2 = [[] for _ in range(N + 1)]
check = [0 for _ in range(N + 1)]
dangerous_towns = [0 for _ in range(N + 1)]
for i in AB:
    info2[i[0] - 1].append([i[1] - 1, 1])
    info2[i[1] - 1].append([i[0] - 1, 1])
for i in C:
    info2[N].append([i - 1, 1])

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
        info[i[0] - 1].append([i[1] - 1, 10**-9])
    else:
        if dangerous_towns[i[1] - 1] == 0:
            info[i[0] - 1].append([i[1] - 1, P])
        elif dangerous_towns[i[1] - 1] == 1:
            info[i[0] - 1].append([i[1] - 1, Q])
    if i[0] - 1 == N - 1:
        info[i[1] - 1].append([i[0] - 1, 10**-9])
    else:
        if dangerous_towns[i[0] - 1] == 0:
            info[i[1] - 1].append([i[0] - 1, P])
        elif dangerous_towns[i[0] - 1] == 1:
            info[i[1] - 1].append([i[0] - 1, Q])

data = [INF]

matrix = lil_matrix((N, N))
for i in range(N):
    matrix[i, i] = 0
for i in range(len(info)):
    for l in range(len(info[i])):
        matrix[i, info[i][l][0]] = info[i][l][1]
print(int(dijkstra(matrix, indices=0)[N - 1]))
