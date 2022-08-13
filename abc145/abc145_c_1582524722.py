import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect
from scipy.special import comb
from scipy.special import perm

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N = int(input())
xy = [list(map(int, input().split())) for _ in range(N)]
L = list(itertools.permutations(xy, 2))
num = math.factorial(N-1) / comb(N, 2)
ans = 0
for i in range(N-1):
    for l in range(i+1, N):
        ans += math.sqrt((xy[i][0]-xy[l][0])**2+(xy[i][1]-xy[l][1])**2)
ans *= num
print(ans)
