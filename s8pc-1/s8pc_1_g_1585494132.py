#!usr/bin/env python3
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
import bisect

MOD = 10 ** 9 + 7
INF = float("inf")
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

N, M = map(int, input().split())
time_limit = [[0] * N for _ in range(N)]
distance = [[INF] * N for _ in range(N)]
for _ in range(M):
    s, t, d, time = map(int, input().split())
    distance[s - 1][t - 1] = distance[t - 1][s - 1] = d
    time_limit[s - 1][t - 1] = time_limit[t - 1][s - 1] = time

dp = [[[INF, 0] for _ in range(2 ** N + 10)] for _ in range(N + 10)]
dp[0][0] = [0, 1]
stack = [(0, 0)]
for _ in range(N - 1):
    next_stack = []
    for now, bits in stack:
        time, num = dp[now][bits]

        for to in range(1, N):
            to_time = time + distance[now][to]

            if bits & (1 << to) or time_limit[now][to] < to_time:
                continue
            to_bits = (1 << to) | bits
            if dp[to][to_bits][0] > to_time:
                if dp[to][to_bits][0] == INF:
                    next_stack.append((to, to_bits))
                dp[to][to_bits] = [to_time, num]
            elif dp[to][to_bits][0] == to_time:
                dp[to][to_bits][1] += num
    stack = next_stack
ans = [INF, 0]
for i in range(1, N):
    time, num = dp[i][2 ** N - 2]
    to_time = time + distance[i][0]

    if time_limit[i][0] >= to_time:
        if ans[0] > to_time:
            ans = [to_time, num]
        elif ans[0] == to_time:
            ans[1] += num

print(" ".join(map(str, ans)) if ans[0] != INF else "IMPOSSIBLE")