import sys
import math
from collections import deque
import copy

N = int(input())
d = [int(input()) for _ in range(N)]
ansMAX = 0
ansMIN = 0
for i in d:
    ansMAX += i
SUM = sum(d)
for p, i in enumerate(d):
    if i > SUM - i:
        ansMIN = 2*i-SUM
        break
    elif p == N-1:
        ansMIN = 0
print(ansMAX)
print(abs(ansMIN))