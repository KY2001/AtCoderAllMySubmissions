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

X = input()
M = int(input())
d = 0
for i in X:
    d = max(d, int(i))
L = -1
R = int(2e18)
while R - L > 1:
    yes = True
    mid = (R + L)//2
    now = 0
    temp = 1
    for i in range(len(X)):
        j = len(X) - i - 1
        now += temp * int(X[j])
        if temp > M:
            yes = False
            break
        if now > M:
            yes = False
            break
        temp *= mid
    if yes:
        L = mid
    else:
        R = mid
print(max(0, (R+L)//2 - d))
