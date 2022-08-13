import sys
import math
from collections import deque
input = sys.stdin.readline
N = int(input())
check = [i for i in range(1, N+1)]
t = [[0 for i in range(9)] for _ in range(9)]
ans = 0
for i in range(1, 10):
    for l in range(1, 10):
        for q in check:
            if int(str(q)[0]) == i and int(str(q)[-1]) == l:
                t[i-1][l-1] += 1
for i in range(1, N+1):
    if str(i)[-1] == "0":
        continue
    elif len(str(i)) == 1:
        ans += t[i-1][i-1]
    else:
        ans += t[int(str(i)[-1])-1][int(str(i)[0])-1]
print(ans)

