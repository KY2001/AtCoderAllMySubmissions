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

N = int(input())
ans = 1
num_list = [0] * (N + 1)
for n in range(2, N+1):
    for i in range(2, 10 ** 3 + 1):
        while n % i == 0:
            num_list[i] += 1
            n //= i
for i in num_list:
    ans *= (i+1)
    ans %= MOD
print(ans)

