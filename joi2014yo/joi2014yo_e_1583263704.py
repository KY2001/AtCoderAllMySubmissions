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


N, K = map(int, input().split())
CR = [list(map(int, input().split())) for _ in range(N)]
AB = [list(map(int, input().split())) for _ in range(K)]

result = []

info1 = [[] for _ in range(N)]
for i in AB:
    info1[i[0] - 1].append([i[1] - 1, 1])
    info1[i[1] - 1].append([i[0] - 1, 1])
for i in range(N):
    result.append(dijkstra(N, info1, i))

info1 = [[] for _ in range(N)]
for i in range(N):
    for l in range(N):
        if result[i][l] <= CR[i][1]:
            info1[i].append([l, CR[i][0]])

print(int(dijkstra(N, info1, 0)[N - 1]))
