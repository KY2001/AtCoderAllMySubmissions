import sys
import math
import itertools
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

R, C = map(int,input().split())
a = [list(map(int,input().split())) for _ in range(R)]
num1 = [0 for _ in range(C)]
for i in range(C):
    for l in range(R):
        if a[l][i] == 1:
            num1[i] += 1
ans = 0
for i in range(2**R):
    num = copy.deepcopy(num1)
    for l in range(R):
        if (i >> l) & 1 == 1:
            for k in range(C):
                if a[l][k] == 0:
                    num[k] += 1
                else:
                    num[k] -= 1
    temp_sum = 0
    for l in num:
        if l >= R/2:
            temp_sum += l
        else:
            temp_sum += R-l
    if temp_sum > ans:
        ans = temp_sum
print(ans)