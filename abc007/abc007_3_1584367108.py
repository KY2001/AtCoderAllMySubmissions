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

R, c = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())
info = [list(input()) for _ in range(R)]

stack = [[sy - 1, sx - 1, 0]]
ans = INF
while len(stack) > 0:
    current = stack.pop(0)
    x, y, num = current[1], current[0], current[2]
    if info[y][x] == ".":
        if x == gx - 1 and y == gy - 1 and ans > current[2]:
            ans = current[2]
        info[y][x] = "#"
        stack.append([y + 1, x, num + 1])
        stack.append([y, x + 1, num + 1])
        stack.append([y - 1, x, num + 1])
        stack.append([y, x - 1, num + 1])
print(ans)
