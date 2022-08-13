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
import numpy as np

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

H, W, K = map(int, input().split())
S = [list(map(int, list(input()))) for _ in range(H)]
ans = INF
for i in range(2 ** (H - 1)):
    num = 0
    p = [0]
    S_part = []
    for j in range(H - 1):
        if (i >> j) & 1:
            if j + 1 - p[-1] > 1:
                S_part.append(S[p[-1]:j + 1])
            else:
                temp_S_part = S[p[-1]:j + 1]
                temp_S_part = np.insert(temp_S_part, 1, np.zeros(W), axis=0)
                S_part.append(temp_S_part)
            p.append(j + 1)
    if p[-1] != H:
        temp_S_part = S[p[-1]:H]
        temp_S_part = np.insert(temp_S_part, 1, np.zeros(W), axis=0)
        S_part.append(temp_S_part)
    num = len(S_part) - 1
    if len(S_part) == 1:
        S_part.append(np.zeros((2, W)))
    for j in range(len(S_part)):
        S_part[j] = np.cumsum(S_part[j], axis=0)
    check = [0] * (len(S_part))
    for j in range(W):
        for l in range(len(S_part)):
            check[l] += S_part[l][-1][j]
        for l in range(len(S_part)):
            if check[l] > K:
                if j == 0:
                    num += INF
                check = [0] * (len(S_part))
                num += 1
                for l in range(len(S_part)):
                    check[l] += S_part[l][-1][j]
                break
    if ans > num:
        ans = num
print(ans)
