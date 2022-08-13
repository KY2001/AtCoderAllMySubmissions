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


def search(y, x, depth):
    global ans
    if s[y][x] == ".":
        if y == H and x == W:
            if depth < ans:
                ans = depth
        if s[y + 1][x] == ".":
            if check[y + 1][x] > depth:
                pos.append([y + 1, x, depth])
                check[y + 1][x] = depth
        elif s[y + 1][x] == "#":
            if check[y + 1][x] > depth:
                search(y + 1, x, depth)
                check[y + 1][x] = depth
        if s[y][x + 1] == ".":
            if check[y][x + 1] > depth:
                pos.append([y, x + 1, depth])
                check[y][x + 1] = depth
        elif s[y][x + 1] == "#":
            if check[y][x + 1] > depth:
                search(y, x + 1, depth)
                check[y][x + 1] = depth
    else:
        if y == H and x == W:
            if depth < ans:
                ans = depth + 1
        if s[y + 1][x] == ".":
            if check[y + 1][x] > depth + 1:
                pos.append([y + 1, x, depth + 1])
                check[y + 1][x] = depth + 1
        elif s[y + 1][x] == "#":
            if check[y + 1][x] > depth:
                search(y + 1, x, depth)
                check[y + 1][x] = depth
        if s[y][x + 1] == ".":
            if check[y][x + 1] > depth + 1:
                pos.append([y, x + 1, depth + 1])
                check[y][x + 1] = depth + 1
        elif s[y][x + 1] == "#":
            if check[y][x + 1] > depth:
                search(y, x + 1, depth)
                check[y][x + 1] = depth


H, W = map(int, input().split())
s = [["$" for _ in range(W + 2)]]
for i in range(H):
    s.append(["$"] + list(input()) + ["$"])
s.append(["$" for _ in range(W + 2)])
check = [[INF] * (W + 2) for _ in range(H + 2)]

ans = INF
pos = deque()
if s[1][1] == ".":
    pos.append([1, 1, 0])
else:
    search(1, 1, 0)
while len(pos) > 0:
    y, x, depth = pos.popleft()
    search(y, x, depth)
print(ans)