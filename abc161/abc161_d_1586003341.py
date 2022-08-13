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

List = [str(i) for i in range(0, 10)]
prev_num = 10
K = int(input())
if K <= 9:
    print(List[K])
else:
    while True:
        List2 = []
        for i in List:
            if i != "0":
                List2.append(i + str(i[-1]))
                if i[-1] != "9":
                    List2.append(i + str(int(i[-1]) + 1))
                if i[-1] != "0":
                    List2.append(i + str(int(i[-1]) - 1))
        List = List2
        if prev_num + len(List) >= K:
            List = list(map(int, List))
            List.sort()
            print(List[K - prev_num])
            sys.exit()
        prev_num += len(List)