import sys
import math
from collections import deque

A, B, X = map(int, input().split())

if A + B > X:
    print(0)
    sys.exit()
if X >= (10 ** 9) * A + B * (math.log10(10 ** 9) // 1 + 1):
    print(10 ** 9)
    sys.exit()


def bisect(under, top):
    N = (under + top) // 2
    if (A * N + B * (math.log10(N) // 1 + 1)) <= X < (
            A * (N + 1) + (B * (math.log10(N + 1) // 1 + 1))):
        print(N)
        sys.exit()
    elif (A * N + (math.log10(N) // 1 + 1) * B) > X:
        bisect(under, (under + top) // 2)
    else:
        bisect((under + top) // 2, top)


bisect(1, 10 ** 9 + 1)
