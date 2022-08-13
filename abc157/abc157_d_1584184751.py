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

N, M, K = map(int, input().split())


class UnionFind:
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        return {r: self.members(r) for r in self.roots()}

    def __str__(self):
        return '\n'.join('{}: {}'.format(r, self.members(r)) for r in self.roots())


friend_checker = UnionFind(N)
direct_friends = [0 for _ in range(N)]

for _ in range(M):
    A, B = map(int, input().split())
    friend_checker.union(A - 1, B - 1)
    direct_friends[A - 1] += 1
    direct_friends[B - 1] += 1

block = [[] for _ in range(N)]
for _ in range(K):
    C, D = map(int, input().split())
    block[C - 1].append(D - 1)
    block[D - 1].append(C - 1)

for i in range(N):
    ans = friend_checker.size(i) - direct_friends[i] - 1
    for l in block[i]:
        if friend_checker.same(i, l):
            ans -= 1
    print(ans)
