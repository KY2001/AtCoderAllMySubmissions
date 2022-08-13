import sys
import math
from collections import deque
input = sys.stdin.readline
N = int(input())
P = list(map(int,input().split()))
check = P[0]
ans = 0
for i in P:
    if i <= check:
        ans += 1
        check = min(check, i)

print(ans)