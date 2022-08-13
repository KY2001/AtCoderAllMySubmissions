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

L = int(input())
ans = 0
for b in range(1, L+1):
    for c in range(1, L+1):
        if b*c*(L-b-c) > ans:
            ans = b*c*(L-b-c)
print(ans)