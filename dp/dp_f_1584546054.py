import sys
import math
import string
import fractions
import random
from operator import itemgetter
import itertools
from collections import deque
import copy
import heapq
from bisect import bisect, bisect_left, bisect_right

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

s = input()
t = input()

info = [deque() for _ in range(26)]
check = []
for i in range(len(s)):
    info[ord(s[i]) - 97].appendleft(i)
ans = [INF] * (max(len(s), len(t)) + 10)
link = [[0, 0, 0] for _ in range(max(len(s), len(t)) + 10)]
info2 = deque()
time = 0
for i in t:
    for l in info[ord(i) - 97]:
        ind = bisect_left(ans, l)
        ans[ind] = l
        info2.append([time, link[ind-1][0], i])
        link[ind] = [time, link[ind-1][0], i]
        time += 1
num = bisect_left(ans, INF)
ans = deque()
a = link[num-1]
while len(ans) < num:
    ans.appendleft(a[2])
    a = info2[a[1]]
print("".join(ans))

