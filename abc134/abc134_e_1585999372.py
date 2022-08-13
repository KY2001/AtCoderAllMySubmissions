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
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

N = int(input())
A = [int(input()) for _ in range(N)]
pos = copy.deepcopy(A)
ans = 0
while len(pos) > 0:
    LIS = deque([])
    for i in range(len(pos)):
        temp = bisect.bisect_left(LIS, pos[i])
        if len(LIS) <= temp:
            LIS.append(pos[i])
        else:
            LIS[temp] = pos[i]
    ans += 1
    pos2 = []
    for i in range(len(pos)):
        if len(LIS) != 0:
            if pos[i] == LIS[0]:
                LIS.popleft()
            else:
                pos2.append(pos[i])
        else:
            pos2.append(pos[i])
    pos = pos2
print(ans)