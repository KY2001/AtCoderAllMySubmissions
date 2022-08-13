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

n = int(input())
c = [int(input()) for _ in range(n)]
p = [[c[0], 1]]
c_zip = []
num = 1
for l in range(1, n):
    if l % 2 == 0:
        if c[l] == p[-1][0]:
            p[-1][1] += 1
        else:
            p.append([c[l], 1])
    else:
        if c[l] != p[-1][0]:
            p[-1] = [c[l], p[-1][1] + 1]
        else:
            p[-1][1] += 1
ans = 0
for i in p:
    if i[0] == 0:
        ans += i[1]
print(ans)