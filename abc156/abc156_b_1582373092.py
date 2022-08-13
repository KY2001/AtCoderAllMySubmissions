import sys
import math
import itertools
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N, K = map(int, input().split())
print(int(((math.log(N, K)) // 1) + 1))
