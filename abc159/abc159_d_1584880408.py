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


def Nc2(n):
    return n * (n - 1) // 2


N = int(input())
A = list(map(int, input().split()))
AA = sorted(A)
num = [0] * (N + 10)
num2 = [0] * (N + 10)
val = 0
for i in range(N - 1):
    if AA[i] == AA[i + 1]:
        val += 1
    else:
        val += 1
        num[AA[i]] = Nc2(val)
        num2[AA[i]] = val
        val = 0
    if i == N - 2:
        val += 1
        num[AA[i + 1]] = Nc2(val)
        num2[AA[i + 1]] = val
summ = sum(num)
for i in range(N):
    print(summ - num[A[i]] + Nc2(num2[A[i]] - 1))
