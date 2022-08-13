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
from bisect import bisect, bisect_left, bisect_right

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)


class LinkedList:
    def __init__(self, val, pre):
        self.prev = pre
        self.value = val


s = input()
t = input()

info = deque(deque() for _ in range(26))
check = []
for i in range(len(s)):
    info[ord(s[i]) - 97].appendleft(i)
ans = [INF] * (max(len(s), len(t)) + 10)
link = [0] * (max(len(s), len(t)) + 10)
for i in t:
    for l in info[ord(i) - 97]:
        ind = bisect_left(ans, l)
        ans[ind] = l
        a = LinkedList(i, link[ind-1])
        link[ind] = a
num = bisect_left(ans, INF)
ans = deque()
a = link[num-1]
while len(ans) < num:
    ans.appendleft(a.value)
    a = a.prev
print("".join(ans))