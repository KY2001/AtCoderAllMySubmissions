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

m = int(input())
n = int(input())

Map = [[] for _ in range(n + 2)]
Map[0] = [0] * (m + 2)
Map[-1] = [0] * (m + 2)
for i in range(1, n + 1):
    Map[i] = [0] + list(map(int, input().split())) + [0]


def search(i, j, num):
    global ans
    if Map[i][j] == 1:
        if num > ans:
            ans = num
        num += 1
        Map[i][j] = 0
        search(i + 1, j, num)
        search(i, j + 1, num)
        search(i, j - 1, num)
        search(i - 1, j, num)
        Map[i][j] = 1


ans = 0

for i in range(1, n + 1):
    for j in range(1, m + 1):
        search(i, j, 1)

print(ans)
