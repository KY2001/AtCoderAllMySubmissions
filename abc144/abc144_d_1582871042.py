import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

a, b, x = map(int, input().split())
if x >= (a ** 2 * b) / 2:
    print(math.atan(2 / a ** 3 * (a ** 2 * b - x)) * (180 / math.pi))
else:
    print(math.atan(a * b ** 2 / (2 * x)) * (180 / math.pi))
