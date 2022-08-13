import sys
import math
from collections import deque
import copy

N, K = map(int, input().split())

s = [int(input()) for _ in range(N)]
if 0 in s:
    print(N)
    sys.exit()
ans = 0
SUM = 1
right = 0
p = 0
for i in range(N):
    if p == 1:
        break
    while True:
        SUM *= s[right]
        if SUM > K:
            SUM /= s[i]
            SUM /= s[right]
            break
        if right - i + 1 >= ans:
            ans = right - i + 1
        right += 1
        if right >= N:
            p = 1
            break
print(ans)
