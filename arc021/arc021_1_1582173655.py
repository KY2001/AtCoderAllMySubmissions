import sys
import math
from collections import deque
import copy

A = []
A.append(["3" for _ in range(6)])
for _ in range(4):
    t = deque(map(int, input().split()))
    t.append("3")
    t.appendleft("3")
    A.append(t)
A.append(["3" for _ in range(6)])

ans = 0
for i in range(1, 5):
    for l in range(1, 5):
        if A[i][l] == A[i - 1][l] or A[i][l] == A[i][l - 1] or A[i][l] == A[i][l + 1] or A[i][l] == A[i + 1][l]:
            ans = 1
if ans == 1:
    print("CONTINUE")
else:
    print("GAMEOVER")
