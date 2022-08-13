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

N, K = map(int, input().split())
a = list(map(int, input().split()))
Min = INF
for i in range(2 ** (N - 1)):
    if bin(i).count("1") == K - 1:
        temp = 0
        M = 0
        for l in range(N - 1):
            if i >> l & 1 == 1:
                temp += (max(max(a[:l+2]), M) - a[l+1]) + 1
                M = max(max(a[:l+2]), M) + 1
        if temp < Min:
            Min = temp
print(Min)
