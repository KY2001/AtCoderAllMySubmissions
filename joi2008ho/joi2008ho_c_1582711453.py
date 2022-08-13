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

N, M = map(int, input().split())
P = [int(input()) for _ in range(N)]
P.append(0)
P.append(0)
LIST = sorted([sum(i) for i in itertools.combinations_with_replacement(P, 2)])
ans = 0
for i in range(len(LIST)):
    index = bisect.bisect_right(LIST, M - LIST[i])
    if index == 0:
        break
    if LIST[i] + LIST[index - 1] > ans:
        ans = LIST[i] + LIST[index - 1]
print(ans)