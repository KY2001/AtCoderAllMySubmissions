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
red = []
blue = []
for _ in range(N):
    X, C = map(str, input().split())
    X = int(X)
    if C == "R":
        red.append(X)
    else:
        blue.append(X)
red.sort()
blue.sort()
for i in red:
    print(i)
for i in blue:
    print(i)