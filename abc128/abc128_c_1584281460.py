import sys
import math
import string
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

N, M = map(int, input().split())
s = [list(map(int, input().split()))[1:] for _ in range(M)]
p = list(map(int, input().split()))


def switch(bit, ans):
    check = [(bit >> i) & 1 for i in range(N)]
    light = 0
    for i in range(M):
        num = 0
        for l in s[i]:
            if check[l - 1] == 1:
                num += 1
        if num % 2 == p[i]:
            light += 1
    if light == M:
        ans += 1
    if bit == 1:
        print(ans)
    else:
        switch(bit - 1, ans)


switch(2 ** N, 0)
