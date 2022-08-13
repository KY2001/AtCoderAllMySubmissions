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

N, Q = map(int, input().split())
A = list(map(int, input().split()))
S = list(map(int, input().split()))
all_gcd = A[0]
for i in range(1, N):
    all_gcd = math.gcd(all_gcd, A[i])
    A[i] = all_gcd
AA = [[A[0], 0]]
for i in range(1, N):
    if A[i] != A[i - 1]:
        AA.append([A[i], i])
for i in S:
    if math.gcd(all_gcd, i) != 1:
        print(math.gcd(all_gcd, i))
    else:
        for j in range(len(AA)):
            if math.gcd(AA[j][0], i) == 1:
                print(AA[j][1] + 1)
                break