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

N = int(input())
X = list(map(int, input().split()))
XX = copy.deepcopy(X)
X.sort()
a = X[N // 2]
b = X[N // 2 - 1]
print(a)
for i in range(1, N):
    if XX[i] == a:
        print(b)
    else:
        print(a)
