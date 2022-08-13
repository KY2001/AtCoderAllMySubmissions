import sys
import math
from collections import deque
input = sys.stdin.readline
H = int(input())
n = 0
for i in range(10**3):
    if H == 1:
        break
    H //= 2
    n += 1
ans = 1
for i in range(n):
    ans *= 2
    ans += 1
print(ans)