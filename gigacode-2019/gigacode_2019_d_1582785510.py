import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect
import numpy

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

H, W, K, V = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]
MIN = INF
for i in A:
    MIN = min(MIN, min(i))
    for l in range(W):
        i[l] += K
if MIN + K > V:
    print(0)
    sys.exit()
for i in range(H):
    A[i] = list(numpy.cumsum(A[i]))
ans = 0
for y in range(H):
    for x in range(W):
        for width in range(1, W - x + 1):
            if ans < width * (H - y):
                money = 0
                for length in range(1, H - y + 1):
                    if x >= 1:
                        money += A[y + length - 1][x + width - 1] - A[y + length - 1][x - 1]
                    else:
                        money += A[y + length - 1][x + width - 1]
                    if money > V:
                        break
                    if width * length > ans:
                        ans = width * length
print(ans)
