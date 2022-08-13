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
aa = [list(map(int,input().split())) for _ in range(R)]
ans = 0
for i in range(2**R):
    a = copy.deepcopy(aa)
    for l in range(R):
        if (i >> l) & 1 == 1:
            for k in range(C):
                if a[l][k] == 0:
                    a[l][k] = 1
                else:
                    a[l][k] = 0
    temp_sum = 0
    for l in range(C):
        num1 = 0
        for k in range(R):
            if a[k][l] == 0:
                num1 += 1
        if num1 >= R/2:
            temp_sum += num1
        else:
            temp_sum += R-num1
    if temp_sum > ans:
        ans = temp_sum
print(ans)