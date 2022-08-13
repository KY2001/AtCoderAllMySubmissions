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

N = int(input())


def answer(info, ans):
    if max(ans) > N:
        return ans
    info2 = []
    for i in info:
        for l in ["3", "5", "7"]:
            info2.append(int(str(i) + l))
    ans += info2
    return answer(info2, ans)


a = sorted(list(set(answer([3, 5, 7], [3, 5, 7]))))
num = 0
for i in range(len(a)):
    if a[i] > N:
        print(num)
        break
    elif all(str(a[i]).count(d) > 0 for d in "753"):
        num += 1
