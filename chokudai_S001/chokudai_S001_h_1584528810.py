import sys
import bisect

INF = 10**9
input = lambda: sys.stdin.readline().strip()
N = int(input())
a = list(map(int, input().split()))
dp = [INF]*(N+10)

for i in a:
    ind = bisect.bisect(dp, i)
    dp[ind] = i

print(bisect.bisect_left(dp, INF))
