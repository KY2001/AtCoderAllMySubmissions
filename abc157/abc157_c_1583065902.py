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
sc = [list(map(int, input().split())) for _ in range(M)]

for i in range(M - 1):
    for l in range(i + 1, M):
        if sc[i][0] == sc[l][0] and sc[i][1] != sc[l][1]:
            print(-1)
            sys.exit()

ans = ["0" for _ in range(N)]
for i in sc:
    ans[i[0] - 1] = str(i[1])
if N != 1 and ans[0] == "0":
    print(-1)
    sys.exit()
if len(str(int("".join(ans)))) != N:
    print(-1)
    sys.exit()
print(int("".join(ans)))
