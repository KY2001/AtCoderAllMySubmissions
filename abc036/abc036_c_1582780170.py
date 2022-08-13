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
a = [int(input()) for _ in range(N)]
aa = sorted(list(set(a)))
aaa = {}
for i in range(len(aa)):
    aaa[aa[i]] = i
b = []
for i in a:
    b.append(aaa[i])
for i in b:
    print(i)


