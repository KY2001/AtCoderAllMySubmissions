import sys
import math
from collections import deque
input = sys.stdin.readline
H, N = map(int,input( ).split())
A = list(map(int,input().split()))
if H <= sum(A):
    print("Yes")
else:
    print("No")