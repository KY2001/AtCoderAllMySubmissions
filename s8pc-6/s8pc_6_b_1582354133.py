import sys
import math
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N = int(input())
AB = [list(map(int, input().split())) for _ in range(N)]

ans = INF
for i in range(N):
    for q in range(N):
        L = min(AB[i][0], AB[q][0])
        R = max(AB[i][0], AB[q][0])
        temp = 0
        for k in AB:
            l = min(k[0], k[1])
            r = max(k[0], k[1])
            if L <= l <= r <= R:
                temp += R - L
            elif l <= L and r <= R:
                temp += R + L - 2 * l
            elif l <= L <= R <= r:
                temp += 2 * (r - l) + (L - R)
            else:
                temp += 2 * r - L - R
        if temp < ans:
            ans = temp
    for q in range(N):
        L = min(AB[i][0], AB[q][1])
        R = max(AB[i][0], AB[q][1])
        temp = 0
        for k in AB:
            l = min(k[0], k[1])
            r = max(k[0], k[1])
            if L <= l <= r <= R:
                temp += R - L
            elif l <= L and r <= R:
                temp += R + L - 2 * l
            elif l <= L <= R <= r:
                temp += 2*(r-l)+(L-R)
            else:
                temp += 2 * r - L - R
        if temp < ans:
            ans = temp
print(ans)
