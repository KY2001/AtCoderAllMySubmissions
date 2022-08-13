import sys
import math
input = sys.stdin.readline
H = int(input())
W = int(input())
N = int(input())
a = max(H,W)
print(math.ceil(N/a))