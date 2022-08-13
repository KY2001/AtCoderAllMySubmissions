#!usr/bin/env python3
import sys
import math
import operator
import functools

prod = functools.partial(functools.reduce, operator.mul)
MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)


def solve():
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
    prime_temp = []
    primes2 = prime_factorization(N - 1)
    List = []
    for i in range(2 ** (len(primes2))):
        prid = prod([primes2[j] if i & (1 << j) else 1 for j in range(len(primes2))])
        if prid != 1:
            List.append(prid)
    List = list(set(List))
    prime_set = list(set(primes + prime_temp))
    for i in prime_set:
        temp = N
        while temp % i == 0:
            temp //= i
        if temp % i == 1:
            List.append(i)
    List = list(set(List))
    print(len(List) + 1 if N not in List else len(List))


if __name__ == "__main__":
    solve()