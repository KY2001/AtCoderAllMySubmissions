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

N, M = map(int, input().split())

A = list(map(int, input().split()))

A.sort(reverse=True)
S = sum(A[0:M])
if S <= A[M - 1] * 4 * M:
    print("Yes")
else:
    print("No")
