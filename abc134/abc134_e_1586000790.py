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
Min = [A[-1]]
for i in range(N - 2, -1, -1):
    temp = bisect.bisect_right(Min, A[i])
    if temp == len(Min):
        Min.append(A[i])
    elif Min[temp] != A[i]:
        Min[temp] = A[i]
    elif temp + 1 != len(Min):
        Min[temp + 1] = A[i]
    else:
        Min.append(A[i])
print(len(Min))