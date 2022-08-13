import sys
import math
from collections import deque
import itertools
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()
ans = 0
N, M = map(int, input().split())
ks = [tuple(map(int, input().split())) for _ in range(M)]
p = list(map(int, input().split()))
t = []
for i in range(N):
    tt = list(itertools.combinations(range(1, N+1), i+1))
    for l in tt:
        t.append(l)
for i in range(len(t)):
    pp = 0
    for l in range(M):
        if len(set(ks[l][1:]) & set(t[i])) % 2 == p[l]:
            pp += 1
    if pp == M:
        ans += 1
print(ans)
