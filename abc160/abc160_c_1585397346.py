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

K, N = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
ans = [0, 0]
for i in range(N - 1):
    if ans[0] < A[i + 1] - A[i]:
        ans = [A[i + 1] - A[i], i]
if (K - A[-1]) + A[0] > ans[0]:
    ans = [(K - A[-1]) + A[0], 0]
print(K - ans[0])
