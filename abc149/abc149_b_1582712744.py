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

A, B, K = map(int, input().split())
if A >= K:
    print(A - K, B)
elif A + B >= K:
    print(0, A + B - K)
else:
    print(0, 0)
