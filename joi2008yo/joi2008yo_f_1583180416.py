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


def bellman_ford(n, edge_info, r): #辺の頂点が0からの場合！！
    """
    n: 頂点の数
    edge_info: [[結ぶ頂点の番号, 結ぶ頂点の番号, 重み], ...]
    r: 始点の番号
    無向グラフにおけるそれぞれの頂点までの最小のコストを返す。
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
            if weight[edge[1]] + edge[2] < weight[edge[0]]:
                weight[edge[0]] = weight[edge[1]] + edge[2]
                changed = True
    return weight


n, k = map(int, input().split())
info = []
for _ in range(k):
    query = list(map(int, input().split()))
    if query[0] == 0:
        ans = bellman_ford(n, info, query[1]-1)
        if ans[query[2]-1] != INF:
            print(ans[query[2]-1])
        else:
            print(-1)
    else:
        info.append([query[1]-1, query[2]-1, query[3]])
