N, K = map(int, input().split())
h = list(map(int, input().split()))

dp = [[10**9 for _ in range(K)] for _ in range(N)]
dp[0] = [0 for _ in range(K)]

for i in range(N):
    for l in range(K):
        if i-(l+1) >= 0:
            dp[i][l] = min(dp[i - (l + 1)]) + abs(h[i] - h[i - (l + 1)])
        else:
            dp[i][l] = min(dp[i])
print(min(dp[N-1]))
