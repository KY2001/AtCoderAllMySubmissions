import sys
import math
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

m = int(input())
mxy = [list(map(int, input().split())) for _ in range(m)]
mxy2 = copy.deepcopy(mxy)
a = mxy[0][0]
b = mxy[0][1]
for i in range(m):
    mxy[i][0] -= a
    mxy[i][1] -= b
n = int(input())
nxy = [tuple(map(int, input().split())) for _ in range(n)]
check = set(nxy)

for i in range(n):
    a = nxy[i][0]
    b = nxy[i][1]
    p = 0
    for l in range(m):
        if (a + mxy[l][0], b + mxy[l][1]) in check:
            p += 1
    if p == m:
        print(a - mxy2[0][0], b - mxy2[0][1])
        sys.exit()
