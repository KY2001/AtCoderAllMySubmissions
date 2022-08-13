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
d = int(input())
n = int(input())
m = int(input())
D = [0]
for i in range(n - 1):
    D.append(int(input()))
D.append(d)
D.sort()
ans = 0
for i in range(m):
    M = int(input())
    p = bisect.bisect_right(D, M)
    ans += min(abs(M - D[p]), abs(M - D[p - 1]))
print(ans)
