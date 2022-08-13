import sys
import math
from collections import deque
input = sys.stdin.readline
a, b = map(int,input().split())
abc = []
abc.append(str(a)*b)
abc.append(str(b)*a)
abc.sort()
print(abc[0])


