import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect
import numpy

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N = int(input())
C = sorted(deque(map(int, input().split())))
B = sorted(deque(map(int, input().split())))
A = sorted(list(map(int, input().split())))
BB = []
for i in B:
    BB.append(N - bisect.bisect_right(A, i))
BB_sum = list(numpy.cumsum(BB[::-1])[::-1])
BB_sum.append(0)
ans = 0
for i in C:
    ans += BB_sum[bisect.bisect_right(B, i)]
print(ans)

