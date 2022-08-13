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
    if A[i] == rr + 1:
        rr += 1
    elif bb == bb +1:
        bb += 1
    else:
        gg += 1
print(((combinations_count(N, rr+1)%(10**9+7))*(combinations_count(N-rr-1, bb+1)%(10**9+7))*(combinations_count(N-rr-bb-2, gg+1)%(10**9+7)%10**9+7)*3))
