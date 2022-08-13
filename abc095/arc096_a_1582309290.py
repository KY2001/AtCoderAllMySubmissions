import sys
import math
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

A, B, C, X, Y = map(int, input().split())

ans = 0
while X > 0 or Y > 0:
    if X > 0 and Y > 0:
        if 2*C <=  A+B:
            X -= 1
            Y -= 1
            ans += 2*C
        else:
            X -= 1
            Y -= 1
            ans += A+B
    elif X > 0:
        if 2*C <= A:
            X -= 1
            ans += 2*C
        else:
            X-= 1
            ans += A
    else:
        if 2*C <= B:
            Y -= 1
            ans += 2*C
        else:
            Y -= 1
            ans += B
print(ans)
