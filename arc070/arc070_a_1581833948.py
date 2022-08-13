import sys
import math
from collections import deque
X = int(input())
sum = 0
for i in range(1, 10**9):
    sum += i
    if sum >= X:
        print(i)
        break