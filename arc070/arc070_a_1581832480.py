import sys
import math
from collections import deque
X = int(input())
place = 0
for i in range(1, 10**9):
    if X-(place + i) > i:
        place += i
    elif X == place +i:
        print(i)
        break