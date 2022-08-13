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
check = [0]*(N+1)
A = [int(input()) for _ in range(N)]
LIS = [INF]*(N+1)
for i in range(N):
    temp = bisect.bisect_left(LIS, A[i])
    check[temp] += 1
    LIS[temp] = A[i]
print(max(check))
