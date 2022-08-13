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
info = list(map(int, input().split()))

info_zip = []
num = 1
for i in range(N - 1):
    if info[i] != info[i + 1]:
        num += 1
    else:
        info_zip.append(num)
        num = 1
if num != 0:
    info_zip.append(num)
ans = 0
for i in range(1, N - 1):
    if ans < sum(info_zip[i - 1:i + 2]):
        ans = sum(info_zip[i - 1:i + 2])
print(ans)
