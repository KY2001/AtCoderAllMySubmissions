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

N = int(input())
alphabets = "abc"
ans = [""]


def password(n, ans):
    n -= 1
    ans2 = copy.deepcopy(ans)
    ans = []
    for i in ans2:
        for l in alphabets:
            ans.append(i + l)
    if n == 0:
        for i in ans:
            print(i)
    else:
        password(n, ans)


password(N, ans)
