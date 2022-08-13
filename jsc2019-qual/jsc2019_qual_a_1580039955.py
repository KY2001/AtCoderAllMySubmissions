import sys
import math
from collections import deque
input = sys.stdin.readline
M, D = map(int,input().split())
ans = 0
for i in range(1, D+1):
    for l in range(1, M+1):
        if int(str(i)[0]) >= 2 and int(str(i)[-1]) >= 2 and len(str(i)) >= 2 and l == int(str(i)[0])*int(str(i)[-1]):
            ans += 1
print(ans)
