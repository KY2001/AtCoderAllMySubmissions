import sys
import math
import fractions
import itertools
from collections import deque
import copy
import heapq
import bisect


def warshall_floyd(d):
    """
    d[i][l]がi→lへのコストを示す隣接行列
    結果としてd[i][l]はi→lへの最短コストになる。
    """
    for i in range(len(d)):
        for l in range(len(d)):
            for k in range(len(d)):
                d[l][k] = min(d[l][k], d[l][i] + d[i][k])
    return d


MOD = float('inf')
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]

result = warshall_floyd(A)
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
