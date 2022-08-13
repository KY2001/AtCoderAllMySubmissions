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

checker = (1 + math.sqrt(1 + 8 * N)) / 2

if checker % 1 != 0:
    print("No")
else:
    checker = checker * (checker - 1) // 2
    print("Yes")
    for i in range(1, int(checker) + 1):
        print(2, i, i + 1 if i != int(checker) else 1)
