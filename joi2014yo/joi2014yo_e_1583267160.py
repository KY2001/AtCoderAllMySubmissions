

import sys
import math
import fractions
import itertools
from collections import deque
import copy
import heapq
import bisect

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


def dijkstra_to_bellman(n, vertices_info):
    edges_info = []
    for i in range(n):
        for l in vertices_info[i]:
            edges_info.append([i, l[0], l[1]])
    return edges_info


N, K = map(int, input().split())
CR = [list(map(int, input().split())) for _ in range(N)]
AB = [list(map(int, input().split())) for _ in range(K)]

result = [[INF for _ in range(N)] for _ in range(N)]
info1 = [[] for _ in range(N)]
for i in AB:
    info1[i[0] - 1].append(i[1] - 1)
    info1[i[1] - 1].append(i[0] - 1)
for i in range(N):
    check = [False for _ in range(N)]
    pos = [[i, 0]]
    check[i] = True
    R = CR[i][1]
    C = CR[i][0]
    while len(pos) > 0:

        index, depth = pos.pop(0)
        if depth + 1 <= R:
            for l in info1[index]:
                if check[l] is False:
                    check[l] = True
                    result[i][l] = C
                    pos.append([l, depth + 1])

info1 = [[] for _ in range(N)]
for i in range(N):
    for l in range(N):
        if result[i][l] != INF:
            info1[i].append([l, result[i][l]])

print(int(bellman_ford(N, dijkstra_to_bellman(N, info1), 0)[N - 1]))
