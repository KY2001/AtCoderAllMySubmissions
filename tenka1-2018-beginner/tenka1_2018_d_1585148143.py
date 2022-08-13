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

N = int(input())

checker = [(i + 1) * (i + 2) // 2 for i in range(1000)]

if N not in checker:
    print("No")
else:
    print("Yes")
    for i in range(1, N + 1):
        print(2, i, i + 1 if i != N else 1)
