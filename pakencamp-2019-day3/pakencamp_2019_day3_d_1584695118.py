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

N = int(input())
S = [list(input()) for _ in range(5)]
dp = [[INF] * 3 for _ in range(N + 10)]
r = sum([1 if S[i][0] == "R" else 0 for i in range(5)])
b = sum([1 if S[i][0] == "B" else 0 for i in range(5)])
w = sum([1 if S[i][0] == "W" else 0 for i in range(5)])
dp[0][0] = 5 - r
dp[0][1] = 5 - b
dp[0][2] = 5 - w
for j in range(1, N):
    r = sum([1 if S[i][j] == "R" else 0 for i in range(5)])
    b = sum([1 if S[i][j] == "B" else 0 for i in range(5)])
    w = sum([1 if S[i][j] == "W" else 0 for i in range(5)])
    dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + 5 - r
    dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + 5 - b
    dp[j][2] = min(dp[j - 1][1], dp[j - 1][0]) + 5 - w
print(min(dp[N-1][0], dp[N-1][1], dp[N-1][2]))
