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


def judge(xx, yy):
    global ans
    if info[yy][xx] == 1:
        ans += 1
    elif info[yy][xx] == 0:
        info[yy][xx] = 2
        stack.append([xx, yy])


W, H = map(int, input().split())
info = [[2] * (W + 4)]
info.append([2]+[0]*(W+2)+[2])
for _ in range(H):
    info.append([2, 0] + list(map(int, input().split())) + [0, 2])
info.append([2]+[0]*(W+2)+[2])
info.append([2] * (W + 4))
ans = 0
stack = deque([[1, 1]])
info[0][0] = 2
while len(stack) > 0:
    x, y = stack.popleft()
    if y % 2 == 1:
        judge(x - 1, y + 1)
        judge(x, y + 1)
        judge(x - 1, y)
        judge(x + 1, y)
        judge(x, y - 1)
        judge(x - 1, y - 1)
    else:
        judge(x + 1, y + 1)
        judge(x, y + 1)
        judge(x - 1, y)
        judge(x + 1, y)
        judge(x, y - 1)
        judge(x + 1, y - 1)

print(ans)
