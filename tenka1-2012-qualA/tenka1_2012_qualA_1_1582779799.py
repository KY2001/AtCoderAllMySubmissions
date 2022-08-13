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

n = int(input())
ans = 1
num1 = 0
num2 = 0
num3 = 1
for i in range(n):
    num1 += num2
    num2 = num3
    num3 = num1
    ans += num1
print(ans)