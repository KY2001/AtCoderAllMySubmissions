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

N = int(input())
c = [int(input())-1 for _ in range(N)]

S = [INF]*(N+1)
S[0] = -INF
for i in range(N):
    S[bisect.bisect_left(S, c[i])] = c[i]
print(N - (bisect.bisect_left(S, INF) - 1)