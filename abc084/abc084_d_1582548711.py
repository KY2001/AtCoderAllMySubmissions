import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()


def judge_prime_num(n):
    if n % 2 == 0:
        return True
    else:
        for num in range(3, int(math.sqrt(n) + 2)):
            if n % num == 0:
                return False
        return True


Q = int(input())
primes = [2]
checker = []
for i in range(3, 10 ** 5 + 1, 2):
    if judge_prime_num(i) is True:
        primes.append(i)
set_primes = set(primes)
for i in primes:
    if (i+1)//2 in set_primes:
        checker.append(i)
for i in range(Q):
    l, r = map(int,input().split())
    print(bisect.bisect_right(checker, r) - bisect.bisect_left(checker, l))
