import sys
import math
from collections import deque
import copy

N = int(input())
A = list(map(int, input().split()))
checkA = [1 for _ in range(10 ** 5 + 10)]
R = 0
ans = 1
for L in range(N):
    while R < N and checkA[A[R]] != -1:
        checkA[A[R]] *= -1
        R += 1
    if R - L > ans:
        ans = R - L
    if R == L:
        R += 1
    if R < N:
        checkA[A[R]] *= -1
    checkA[L] *= -1
print(ans)
