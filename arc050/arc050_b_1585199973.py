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

R, B = map(int, input().split())
x, y = map(int, input().split())


def calc(num):
    value = num + min((R - x * num), (B - num) // y)
    return value


def search(L, R):
    val = (L + R) // 2
    check = [calc(i) for i in range(max(0, val - 100), val + 100)]
    if calc(val) == max(check):
        print(calc(val))
    elif val - 100 + check.index(max(check)) <= val:
        search(L, val)
    else:
        search(val, R)


search(0, INF)
