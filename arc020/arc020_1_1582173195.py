import sys
import math
from collections import deque
import copy
import bisect

A, B = map(int,input().split())

if abs(A) == abs(B):
    print("Draw")
elif abs(A) > abs(B):
    print("Bug")
else :
    print("Ant")