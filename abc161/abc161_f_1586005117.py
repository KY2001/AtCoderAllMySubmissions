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


def prime_factorization(n):
    """
    nを素因数分解したリストを返す。
    n >= 2
    """
    ans = []
    for i in range(2, int(math.sqrt(n) + 2)):
        if n % i == 0:
            while n % i == 0:
                ans.append(i)
                n //= i
    if n != 1:
        ans.append(n)
    return ans


N = int(input())
ans = 0
primes = prime_factorization(N)
primes2 = prime_factorization(N - 1)
List = []
for i in range(2 ** (len(primes2))):
    temp = []
    for j in range(len(primes2)):
        if i & (1 << j):
            temp.append(primes2[j])
        temp2 = 1
        if len(temp) > 0:
            for l in temp:
                temp2 *= l
            List.append(temp2)
List = list(set(List))
prime_set = list(set(primes))
for i in prime_set:
    temp = N
    while temp % i == 0:
        temp //= i
    if temp == 1:
        List.append(i)
    elif temp % i == 1:
        List.append(i)
print(len(List) + 1)