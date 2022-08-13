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
import scipy.sparse
from scipy.sparse.csgraph import shortest_path

MOD = 10 ** 9 + 7
INF = 10 ** 18
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

N, X, Y = map(int, input().split())
L = min(X, Y)
R = max(X, Y)

ans = [0] * (N - 1)

for i in range(1, N):
    for j in range(i + 1, N + 1):
        ans[min(j - i, abs(L - i) + abs(R - j) + 1) - 1] += 1
for i in ans:
    print(i)
