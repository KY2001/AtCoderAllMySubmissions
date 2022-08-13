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

s = input()
N = len(s)
p = 0
g = 0
ans = 0
for i in range(N):
    if s[i] == "g":
        if p + 1 <= g:
            ans += 1
            p += 1
        else:
            g += 1
    else:
        if p + 1 <= g:
            p += 1
        else:
            ans -= 1
            g += 1
print(ans)
