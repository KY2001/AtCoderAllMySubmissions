#!usr/bin/env python3
import sys

MOD = 10 ** 9 + 7
INF = 10 ** 18
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

N, M = map(int, input().split())
keys = []
for _ in range(M):
    a, b = map(int, input().split())
    bits = sum([1 << (i - 1) for i in map(int, input().split())])
    keys.append([a, bits])

dp = [[INF] * (2 ** N + 10) for _ in range(M + 10)]
dp[0][0] = 0

for i in range(M):
    for j in range(2 ** N):
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j])
        dp[i + 1][j | keys[i][1]] = min(dp[i + 1][j | keys[i][1]], dp[i][j] + keys[i][0])
print(dp[M][2 ** N - 1] if dp[M][2 ** N - 1] != INF else -1)