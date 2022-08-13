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
p = [0 for _ in range(10 ** 6 + 2)]
for i in range(n):
    a, b = map(int, input().split())
    p[a] -= 1
    p[b + 1] += 1
p = list(itertools.accumulate(p))
print(abs(min(p)))
