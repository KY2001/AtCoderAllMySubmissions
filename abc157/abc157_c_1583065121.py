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
s, c = [0 for _ in range(M)], [0 for _ in range(M)]
for i in range(M):
    s[i], c[i] = map(int, input().split())
if max(s) > N:
    print(-1)
    sys.exit()
ans = ["0" for _ in range(N)]
for i in range(len(s)-1):
    for l in range(i+1, len(s)):
        if s[i] == s[l] and c[i] != c[l]:
            print(-1)
            sys.exit()
for i in range(M):
    ans[s[i]-1] = str(c[i])
if ans[0] == "0":
    print(-1)
    sys.exit()
for i in ans:
    if len(i) > 1:
        print(-1)
        sys.exit()
print(int("".join(ans)))