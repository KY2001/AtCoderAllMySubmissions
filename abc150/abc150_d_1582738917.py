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
a = list(map(int, input().split()))
for i in range(N):
    a[i] //= 2


def lcm(x, y):
    return (x * y) // fractions.gcd(x, y)


LCM = a[0]
if LCM > M:
    print(0)
    sys.exit()

for i in range(N - 1):
    LCM = lcm(a[i], a[i + 1])

ans = math.floor((M / LCM - 1) / 2) + 1

print(ans)
