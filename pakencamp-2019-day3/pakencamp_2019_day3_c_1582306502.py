import sys
import math
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N, M = map(int,input().split())
A = [list(map(int,input().split())) for _ in range(N)]

ans = 0

for i in range(M):
    for l in range(i+1,M):
        score_sum = 0
        for k in range(N):
            score_sum += max(A[k][i], A[k][l])
        if score_sum > ans:
            ans = score_sum
print(ans)