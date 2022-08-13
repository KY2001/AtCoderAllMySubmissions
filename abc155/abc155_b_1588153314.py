#!usr/bin/env python3
import sys
import math
import string
import collections
import fractions
import random
from operator import itemgetter
import itertools
from collections import deque
import copy
import heapq
import bisect

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

N = int(input())
A = list(map(int,input().split()))
for i in A:
    if i%2 == 0 and i%3 != 0 and i%5 != 0:
        print("DENIED")
        sys.exit()
print("APPEOVED")