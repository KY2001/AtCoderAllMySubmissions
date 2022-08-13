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
from bisect import bisect, bisect_left, bisect_right

MOD = 10 ** 9 + 7
INF = 10 ** 18
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

M = int(input())
d = [0] * M
c = [0] * M
for i in range(M):
    d[i], c[i] = map(int, input().split())  # dがc回続く
SUM = 0
for i in range(M):
    SUM += d[i] * c[i]
times = SUM // 9
print(sum(c) + times - 1)
