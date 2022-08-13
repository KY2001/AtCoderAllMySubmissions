import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N, M = map(int, input().split())
sc = [list(map(int, input().split())) for _ in range(M)]

ans = []
if N == 1:
    for i in range(0, 10 ** N):
        ii = str(i)
        p = 0
        for l in sc:
            if int(ii[l[0] - 1]) != l[1]:
                p = 1
        if p == 0:
            ans.append(i)
    if len(ans) == 0:
        print(-1)
        sys.exit()
    print(min(ans))

else:
    for i in range(10 ** (N - 1), 10 ** N):
        ii = str(i)
        p = 0
        for l in sc:
            if int(ii[l[0] - 1]) != l[1]:
                p = 1
        if p == 0:
            ans.append(i)
    if len(ans) == 0:
        print(-1)
        sys.exit()
    print(min(ans))

