import math

from operator import mul
from functools import reduce

def combinations_count(n, r):
    r = min(r, n - r)
    numer = reduce(mul, range(n, n - r, -1), 1)
    denom = reduce(mul, range(1, r + 1), 1)
    return numer // denom


N = int(input())
A = list(map(int,input().split()))
r = 0
b = 0
g = 0
rr = 0
bb = 0
gg = 0
for i in range(N):
    if A[i] == rr:
        rr += 1
    elif A[i] == bb:
        bb += 1
    else:
        gg += 1
c = {rr,bb,gg}
cc = len(c)
print((((combinations_count(N, rr)%(10**9+7))*(combinations_count(N-rr, bb)%(10**9+7))*(combinations_count(N-rr-bb, gg)%(10**9+7))*combinations_count(3,cc-1))%(10**9+7)))