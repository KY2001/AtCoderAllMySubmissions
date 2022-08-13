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


def judge(y, x, dis):
    if info[y][x] == ".":
        info[y][x] = "#"
        stack.append([y, x, dis + 1])


H, W = map(int, input().split())
info = [["#"] * (W + 2)]
for _ in range(H):
    info.append(["#"] + list(input()) + ["#"])
info.append(["#"] * (W + 2))
white = 0
for i in range(H + 2):
    for j in range(W + 2):
        if info[i][j] == ".":
            white += 1

stack = deque([[1, 1, 0]])
while len(stack) > 0:
    y, x, dis = stack.popleft()
    if y == H and x == W:
        ans = dis
        break
    judge(y + 1, x, dis)
    judge(y, x + 1, dis)
    judge(y - 1, x, dis)
    judge(y, x - 1, dis)
    if len(stack) == 0:
        print(-1)
        sys.exit()
print(white - dis - 1)
