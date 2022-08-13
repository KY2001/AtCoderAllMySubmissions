import sys

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

N, K = map(int, input().split())


def debug(n, choice):
    if n == 0:
        if 0 not in choice:
            print("Nothing")
        else:
            print("Found")
    else:
        T = list(map(int, input().split()))
        choice2 = []
        for i in T:
            for l in choice:
                choice2.append(i ^ l)
        debug(n - 1, choice2)


debug(N - 1, list(map(int, input().split())))
