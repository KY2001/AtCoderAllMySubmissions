import sys
import math
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N, M = map(int, input().split())
xy = [tuple(map(int, input().split())) for _ in range(M)]
for i in range(M):
    xy.append(xy[i][::-1])
xy = set(xy)
ans = 0
for i in range(2 ** N):
    c = []
    for l in range(N):
        if (i >> l & 1) == 1:
            c.append(l + 1)
    p = 0
    for l in range(len(c)):
        if p == 1:
            break
        for k in range(l + 1, len(c)):
            if tuple([c[l], c[k]]) not in xy:
                p = 1
                break
        if p == 0 and l == len(c) - 1 and len(c) > ans:
            ans = len(c)
print(ans)
