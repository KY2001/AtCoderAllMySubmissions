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

n = int(input())


def judge_prime_num(n):
    if n == 2:
        return True
    elif n % 2 == 0:
        return False
    else:
        for num in range(3, int(math.sqrt(n) + 2)):
            if n % num == 0:
                return False
        return True


ans = 0
for i in range(2, n):
    if judge_prime_num(i) is True:
        ans += 1
print(ans)
