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

K = int(input())
ans = 0
for i in range(1, K+1):
    for j in range(1, K+1):
        for k in range(1, K+1):
            ans += math.gcd(k, math.gcd(i, j))
print(ans)