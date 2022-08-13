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
ans = [["a", 0]]
for i in range(N - 1):
    ans2 = copy.deepcopy(ans)
    ans = []
    for l in ans2:
        for k in range(min(l[1] + 2, i + 2)):
            ans.append([l[0] + alphabets[k], k])
for i in ans:
    print(i[0])
