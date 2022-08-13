#!usr/bin/env python3
import sys
import math
import string
import collections
import fractions
import random
from operator import itemgetter
import itertools
from collections import deque
import copy
import heapq
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

X, Y, A, B, C = map(int, input().split())
p = list(map(int, input().split()))
q = list(map(int, input().split()))
r = list(map(int, input().split()))

p.sort()
q.sort()
r.sort()

ans = sum(p[-X:]) + sum(q[-Y:])

for i in range(1, C+1):
    if p[0] <= q[0] <= r[-1]:
        ans += r.pop(-1)
        ans -= p.pop(0)
    elif q[0] <= p[0] <= r[-1]:
        ans += r.pop(-1)
        ans -= q.pop(0)
    elif q[0] <= r[-1]:
        ans += r.pop(-1)
        ans -= q.pop(0)
    elif p[0] <= r[-1]:
        ans += r.pop(-1)
        ans -= p.pop(0)
    else:
        break
print(ans)