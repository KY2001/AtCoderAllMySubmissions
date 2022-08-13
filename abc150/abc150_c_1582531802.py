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

N = int(input())
L = list(itertools.permutations(list(range(1, N + 1)), N))
P = tuple(map(int, input().split()))
Q = tuple(map(int, input().split()))
for num, i in enumerate(L):
    if i == P:
        a = num
    if i == Q:
        b = num
print(abs(a - b))
