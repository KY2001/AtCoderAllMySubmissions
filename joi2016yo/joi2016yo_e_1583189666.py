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


def dijkstra(n, vertices_info, r):  # 辺の頂点が0からの場合！！
    """
    n:頂点の数
    vertices_info:頂点の数のインデックスに[[終点の頂点, 結ぶ辺の重み], ...]を収納したリスト。
    r:最短経路の始点
    bellman_to_dijkstraを利用してvertices_infoを容易に用意できる。
    O(V*logV + E)で有向グラフにおけるそれぞれの頂点までの最小のコストを返す。
    辺の重みがマイナスの場合使えない。
    """
    weight = [INF for i in range(n)]
    weight[r] = 0
    vertices_index = []
    heapq.heappush(vertices_index, [r, 0])
    while len(vertices_index) > 0:
        u = heapq.heappop(vertices_index)
        for v in vertices_info[u[0]]:
            if u[1] + v[1] < weight[v[0]]:
                weight[v[0]] = u[1] + v[1]
                heapq.heappush(vertices_index, [v[0], weight[v[0]]])
    return weight


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

print(dijkstra(N, info, 0)[N - 1])
