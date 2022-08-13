import sys
import math
import string
import collections
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

D, N = map(int, input().split())
T = [int(input()) for _ in range(D)]
ABC = [list(map(int, input().split())) for _ in range(N)]
ans = [[0] * (N + 10) for _ in range(D + 10)]
for i in range(D-1):
    for j in range(N):
        if ABC[j][0] <= T[i+1] <= ABC[j][1]:
            for k in range(N):
                if ABC[k][0] <= T[i] <= ABC[k][1]:
                    ans[i+1][j] = max(ans[i+1][j], ans[i][k] + abs(ABC[k][2] - ABC[j][2]))
print(max(ans[D-1]))