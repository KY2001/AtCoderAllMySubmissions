import sys
import math
from collections import deque
import copy

N = int(input())
s = [input() for _ in range(N)]
ss = [[] for _ in range(N)]

for i in range(N):
    t = list(s[i])
    tt = deque([])
    for l in t:
        tt.appendleft(l)
    ss[i].append("".join(tt))
    ss[i].append(s[i])
ss.sort()
for i in ss:
    print(i[1])
