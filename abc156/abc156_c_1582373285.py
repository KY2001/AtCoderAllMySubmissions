import sys
import math
import itertools
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N = int(input())
X = list(map(int,input().split()))
ans = INF
for i in range(1, 101):
    temp = 0
    for l in X:
        temp += (l-i)**2
    if temp < ans:
        ans = temp
print(ans)