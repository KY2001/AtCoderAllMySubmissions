import sys
import math
import string
import fractions
import random
from operator import itemgetter
import itertools
from collections import deque
import copy
import heapq
from bisect import bisect, bisect_left, bisect_right

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

N, A, B = map(int, input().split())
dis = B - A - 1
if dis % 2 == 0:
    print(min(max(A, B) - 1, N - min(A, B)))
else:
    print((dis + 1) // 2)