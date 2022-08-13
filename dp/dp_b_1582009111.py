INF = 10**9
N, K = map(int, input().split())
h = list(map(int, input().split()))

dp = [INF for _ in range(N)]
dp[0] = 0

for i in range(1, N):
    MIN = INF
    for l in range(K):
        if i-(l+1) >= 0:
            MIN = min(MIN, dp[i - (l + 1)] + abs(h[i] - h[i - (l + 1)]))
    dp[i] = MIN
print(dp[N - 1])
