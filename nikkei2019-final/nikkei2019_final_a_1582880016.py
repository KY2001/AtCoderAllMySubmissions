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

N = int(input())
A = list(map(int, input().split()))
A_sum = list(itertools.accumulate(A))
for k in range(N):
    ans = 0
    for i in range(N - k):
        if i > 0:
            if A_sum[i + k] - A_sum[i - 1] > ans:
                ans = A_sum[i + k] - A_sum[i - 1]
        else:
            if A_sum[i + k] > ans:
                ans = A_sum[i + k]
    print(ans)
