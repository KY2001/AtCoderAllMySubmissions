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

H, W, K = map(int, input().split())
S = [list(map(int, list(input()))) for _ in range(H)]
ans = INF
for i in range(2 ** (H - 1)):
    p = deque()
    for j in range(H - 1):
        if (i >> j) & 1:
            p.append(j + 1)
    num = len(p)
    if len(p) == 0:
        check = 0
        for j in range(W):
            temp_sum = sum([S[l][j] for l in range(H)])
            if temp_sum > K:
                num = INF
            if check + temp_sum > K:
                check = temp_sum
                num += 1
            else:
                check += temp_sum
    else:
        p.appendleft(0)
        p.append(H)
        check = [0] * (len(p) - 1)
        for j in range(W):
            for l in range(len(p) - 1):
                if p[l + 1] - p[l] == 1:
                    check[l] += S[l][j]
                else:
                    temp_sum = sum([S[t][j] for t in range(p[l], p[l + 1])])
                    if temp_sum > K:
                        num = INF
                        break
                    check[l] += temp_sum
            for l in check:
                if l > K:
                    num += 1
                    for k in range(len(p) - 1):
                        if p[k + 1] - p[k] == 1:
                            check[k] = S[k][j]
                        else:
                            temp_sum = sum([S[t][j] for t in range(p[k], p[k + 1])])
                            if temp_sum > K:
                                num = INF
                            check[k] = temp_sum
                    break
    if num < ans:
        ans = num
print(ans)
