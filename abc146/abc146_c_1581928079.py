import sys
import math
from collections import deque

A, B, X = map(int, input().split())

if A >= X or B >= X:
    print(0)
    sys.exit()


def bisect(under, top):
    N = (under + top) // 2
    if (A * N + B * (math.log10(N)//1 + 1)) <= X < (A * (N+1) + ((math.log10(N+1)//1 + 1) * B)) and N <= 10**9:
        print(N)
        sys.exit()
    elif (A * N + B * (math.log10(N)//1 + 1)) <= X < (A * (N+1) + ((math.log10(N+1)//1 + 1) * B)):
        print(10**9)
        sys.exit()
    elif (A * N + (math.log10(N)//1 + 1) * B) > X:
        bisect(under, (under+top)//2)
    else :
        bisect((under+top)//2, top)


bisect(-1, 10**18+1)