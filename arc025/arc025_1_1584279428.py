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
import bisect

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

D = list(map(int, input().split()))
J = list(map(int, input().split()))


def gold(day, ans):
    ans += max(D[day], J[day])
    if day == 6:
        print(ans)
    else:
        gold(day + 1, ans)


gold(0, 0)
