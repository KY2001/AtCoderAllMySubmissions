import sys
import math
import itertools
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N, R = map(int,input().split())

if N >= 10:
    print(R)
else:
    print(R+100*(10-N))