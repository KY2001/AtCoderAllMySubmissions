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


def distance(x1, y1, x2, y2):
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)


N, M = map(int, input().split())
xyr = [list(map(int, input().split())) for _ in range(N)]
xy = [list(map(int, input().split())) for _ in range(M)]
dis = []
for i in range(N):
    for l in range(M):
        dis.append(distance(xyr[i][0], xyr[i][1], xy[l][0], xy[l][1]) - xyr[i][2])
if M >= 2:
    for i in range(M - 1):
        for l in range(i + 1, M):
            dis.append((distance(xy[i][0], xy[i][1], xy[l][0], xy[l][1])) / 2)
if len(dis) != 0:
    print(min(dis))
else:
    print(min([i[2] for i in xyr]))
