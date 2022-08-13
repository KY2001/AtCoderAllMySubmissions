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

A = [list(map(int,input().split())) for _ in range(3)]
N = int(input())
b = [int(input()) for _ in range(N)]

for i in b:
    for l in A:
        for c in range(3):
            if l[c] == i:
                l[c] = -1
for i in A:
    if set(i) == {-1}:
        print('Yes')
        sys.exit()
for i in range(3):
    if A[0][i] == A[1][i] == A[2][i] == -1:
        print("Yes")
        sys.exit()
if A[0][0] == A[1][1] == A[2][2]:
    print("Yes")
    sys.exit()
if A[2][0] == A[1][1] == A[0][2] == -1:
    print("Yes")
    sys.exit()
print("No")