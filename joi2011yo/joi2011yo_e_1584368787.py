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
import bisect

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

H, W, N = map(int, input().split())
ans = 0
info = [[] for _ in range(H + 2)]
info[0] = ["X"] * (W + 2)
for i in range(1, H + 1):
    info[i] = ["X"] + list(input()) + ["X"]
info[-1] = ["X"] * (W + 2)
for i in range(H + 2):
    for l in range(W + 2):
        if info[i][l] == "S":
            x = l
            y = i
            break
info2 = copy.deepcopy(info)

for i in range(1, 10):
    info = copy.deepcopy(info2)
    stack = [[x, y, 0]]
    while len(stack) > 0:
        xx, yy, dis = stack.pop(0)
        p = info[yy][xx]
        if info[yy][xx] == str(i):
            ans += dis
            x = xx
            y = yy
            break
        else:
            info[yy][xx] = "X"
            if info[yy + 1][xx] != "X":
                stack.append([xx, yy + 1, dis + 1])
            if info[yy - 1][xx] != "X":
                stack.append([xx, yy - 1, dis + 1])
            if info[yy][xx + 1] != "X":
                stack.append([xx + 1, yy, dis + 1])
            if info[yy][xx - 1] != "X":
                stack.append([xx - 1, yy, dis + 1])
print(ans)
