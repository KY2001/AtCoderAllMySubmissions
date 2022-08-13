import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect
import heapq

MOD = float('inf')
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()


def bellman_ford(n, edge_info, r):  # 辺の頂点が0からの場合！！
    """
   n: 頂点の数
    edge_info: [[辺の始点の頂点,辺の終点の頂点, 重み], ...]
    r: 始点の番号
    O(V*E)で有向グラフにおけるそれぞれの頂点までの最小のコストを返す。
    """
    weight = [INF for _ in range(n)]
    weight[r] = 0
    changed = True
    while changed:  # (=True)
        changed = False
        for edge in edge_info:
            if weight[edge[0]] + edge[2] < weight[edge[1]]:
                weight[edge[1]] = weight[edge[0]] + edge[2]
                changed = True
    return weight


def dijkstra_to_bellman(vertices_info):
    std = []
    for i in range(len(vertices_info)):
        for l in range(len(vertices_info[i])):
            std.append([i, vertices_info[i][l][0], vertices_info[i][l][1]])
    return std


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
        info[i[0] - 1].append([i[1] - 1, 0])
    else:
        if dangerous_towns[i[1] - 1] == 0:
            info[i[0] - 1].append([i[1] - 1, P])
        elif dangerous_towns[i[1] - 1] == 1:
            info[i[0] - 1].append([i[1] - 1, Q])
    if i[0] - 1 == N - 1:
        info[i[1] - 1].append([i[0] - 1, 0])
    else:
        if dangerous_towns[i[0] - 1] == 0:
            info[i[1] - 1].append([i[0] - 1, P])
        elif dangerous_towns[i[0] - 1] == 1:
            info[i[1] - 1].append([i[0] - 1, Q])

print(bellman_ford(N, dijkstra_to_bellman(info), 0)[N - 1])
