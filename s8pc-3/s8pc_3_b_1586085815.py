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
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

H, W, K = map(int, input().split())
c = [list(map(int, list(input()))) for _ in range(H)]
ans = 0
cc = copy.deepcopy(c)
for z in range(H):
    for m in range(W):
        c = copy.deepcopy(cc)
        c[z][m] = 0
        temp_ans = 0
        repeat_num = -1
        p = 1
        while p:
            p = 0
            for i in range(H):
                num = 1
                for j in range(W):
                    if j != W - 1:
                        if c[i][j] == c[i][j + 1] and c[i][j] != -1:
                            num += 1
                        elif num >= K:
                            temp_ans += 2 ** repeat_num * c[i][j] * num
                            for k in range(j - num + 1, j + 1):
                                c[i][k] = 0
                            num = 1
                            p = 1
                        else:
                            num = 1
                    elif num >= K:
                        temp_ans += 2 ** repeat_num * c[i][j] * num
                        for k in range(j - num + 1, j + 1):
                            c[i][k] = 0
                        num = 1
                        p = 1
            for i in reversed(range(H)):
                for j in reversed(range(W)):
                    if not c[i][j]:
                        if i == 0:
                            c[i][j] = -1
                        else:
                            for k in reversed(range(i)):
                                if c[k][j] != 0:
                                    c[i][j] = c[k][j]
                                    c[k][j] = 0
                                    break
            repeat_num += 1
            if repeat_num == 0:
                p = 1
        ans = max(ans, temp_ans)
print(ans)