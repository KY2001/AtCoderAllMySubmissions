import sys
import math
from collections import deque
input = sys.stdin.readline
H , A = map(int,input().split())
for i in range(1, 10**9):
    H -= A
    if H <= 0:
        print(i)
        break