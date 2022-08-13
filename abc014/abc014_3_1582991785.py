import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect
import numpy as np

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()
n = int(input())
p = np.zeros(10 ** 6 + 1, np.int32)
for i in range(n):
    a, b = map(int,input().split())
    p[max(0, a-1)] -= 1
    p[b] += 1
p = np.cumsum(p)
print(abs(min(p)))