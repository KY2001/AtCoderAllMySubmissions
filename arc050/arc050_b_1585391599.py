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

R, B = map(int, input().split())
x, y = map(int, input().split())


def check(K):
    if math.ceil(K / (y - 1) * y - B / (y - 1)) <= K / (1 - x) - R / (1 - x):
        return True
    else:
        return False


def search(L, R):
    if check((L + R) // 2) and not check((L + R) // 2 + 1):
        return (L + R) // 2
    elif not check((L + R) // 2):
        return search(L, (L + R) // 2)
    else:
        return search((L + R) // 2, R)


print(search(0, 10 ** 19))
