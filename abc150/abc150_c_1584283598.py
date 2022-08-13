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

N = int(input())
P = list(map(int, input().split()))
Q = list(map(int, input().split()))


def dictionary(info, n):
    if n == 1:
        return info
    MAX = max(info[0])
    info2 = []
    for i in range(MAX+1):
        for l in info:
            p = copy.deepcopy(l)
            p.insert(i, MAX+1)
            info2.append(p)
    return dictionary(info2, n - 1)


ans = sorted(dictionary([[1]], N))
print(abs(ans.index(P) - ans.index(Q)))
