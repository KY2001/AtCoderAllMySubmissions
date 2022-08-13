import sys
import bisect

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()
N = int(input())
a = list(map(int, input().split()))
dp = [INF]*(N+10)

for i in a:
    ind = bisect.bisect(dp, i)
    if dp[ind] > i:
        dp[ind] = i

print(bisect.bisect_left(dp, INF))
