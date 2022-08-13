import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect

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

ans = 0
for i in range(H):
    for l in range(W):
        for width in range(W - l):
            money = 0
            for length in range(H - i):
                for k in range(l, l + width + 1):
                    money += A[i + length][k]
                if money > V:
                    break
                if (width + 1) * (length + 1) > ans:
                    ans = (width + 1) * (length + 1)
print(ans)
