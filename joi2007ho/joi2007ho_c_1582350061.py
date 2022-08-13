import sys
import math
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

n = int(input())
xy = sorted([list(map(int, input().split())) for _ in range(n)])
check = [[] for _ in range(5001)]
for i in range(n - 1):
    if xy[i][0] != xy[i + 1][0]:
        check[xy[i][0]] = [0 for _ in range(xy[i][1] + 1)]
    if i == n - 2:
        check[xy[i + 1][0]] = [0 for _ in range(xy[i + 1][1] + 1)]

for i in xy:
    check[i[0]][i[1]] = 1


def distance(x1, y1, x2, y2):
    return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)


for i in xy:
    check[i[0]][i[1]] = 1

ans = 0
for i in range(n):
    for l in range(i + 1, n):
        a = xy[i][0]
        b = xy[i][1]
        c = xy[l][0]
        d = xy[l][1]
        if -b + d + c >= 0 and 0 <= a - c + d < len(check[-b + d + c]):
            if check[-b + d + c][a - c + d] == 1:
                a, b, c, d = c, d, -b + d + c, a - c + d
                if -b + d + c >= 0 and 0 <= a - c + d < len(check[-b + d + c]):
                    if (check[-b + d + c][a - c + d] == 1) and ans < distance(c, d,
                                                                              -b + d + c,
                                                                              a - c + d) ** 2:
                        ans = distance(a, b, c, d) ** 2
        if b - d + c >= 0 and 0 <= -a + c + d < len(check[b - d + c]):
            if check[b - d + c][-a + c + d] == 1:
                a, b, c, d = c, d, b - d + c, -a + c + d
                if b - d + c >= 0 and 0 <= -a + c + d < len(check[b - d + c]):
                    if (check[b - d + c][-a + c + d] == 1) and ans < distance(c, d,
                                                                              -b + d + c,
                                                                              a - c + d) ** 2:
                        ans = distance(a, b, b - d + c, -a + c + d) ** 2
print(int(ans))
