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

A, B, K, L = map(int, input().split())

print(B * (K // L) + A * (K % L) if B*math.ceil(K/L) >= B * (K // L) + A * (K % L) else B*math.ceil(K/L))
