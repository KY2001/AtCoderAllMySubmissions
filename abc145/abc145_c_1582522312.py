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
xy = [list(map(int,input().split())) for _ in range(N)]
L = list(itertools.permutations(xy))
ans = 0
for i in L:
    dis = 0
    for l in range(N-1):
        dis += math.sqrt((i[l][0]-i[l+1][0])**2 + (i[l][1] - i[l+1][1])**2)
    ans += dis
print(ans / len(L))