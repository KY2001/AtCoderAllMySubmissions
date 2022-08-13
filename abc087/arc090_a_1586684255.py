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
itn = int

sys.setrecursionlimit(10 ** 8)

N = int(input())
A1 = list(map(int,input().split()))
A2 = list(map(int,input().split()))

ans = 0
for i in range(100):
    ans = max(ans, sum(A1[0:i+1]) + sum(A2[i:100]))
print(ans)
