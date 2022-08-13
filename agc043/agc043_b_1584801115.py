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
a = list(input())
a = list(map(int, a))
a.sort()
if 1 in a:
    if 2 in a:
        if 3 in a:
            l = a.index(2) - 1
            r = a.index(3) - 1
            if r - l == 1:
                print(1)
            else:
                print(0)
        else:
            print(1)
    else:
        if 3 in a:
            print(2)
        else:
            print(0)
else:
    if 2 in a:
        if 3 in a:
            print(1)
        else:
            print(0)
    else:
        print(0)
