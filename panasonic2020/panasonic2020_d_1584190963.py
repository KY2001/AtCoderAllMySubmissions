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
import bisect

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()
alphabets = string.ascii_lowercase

N = int(input())
ans = ["0"]
for i in range(1, N):
    ans2 = copy.deepcopy(ans)
    ans = []
    for l in ans2:
        for k in range(int(l[-1]) + 2):
            ans.append(l + str(k))
for i in ans:
    s = ""
    for l in range(N):
        s += alphabets[int(i[l])]
    print(s)



