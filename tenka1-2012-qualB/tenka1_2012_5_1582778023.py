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

a,b,c = map(int,input().split())
for i in range(1, 128):
    if i % 3 == a and i % 5 == b and i % 7 == c:
        print(i)
