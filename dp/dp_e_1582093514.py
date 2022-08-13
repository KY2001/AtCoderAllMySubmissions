INF = 10 ** 9 + 7
N, W = map(int, input().split())
weight = []
value = []
for i in range(N):
    tempW, tempV = map(int, input().split())
    weight.append(tempW)
    value.append(tempV)

dp = [[INF for _ in range(N * 300)] for _ in range(N)]
for i in range(value[0]):
    dp[0][i] = weight[0]

for i in range(N):
    for l in range(N * 300):
        if l - value[i] >= 0:
            dp[i][l] = min(dp[i - 1][l], dp[i - 1][l - value[i]] + weight[i])
        else:
            dp[i][l] = min(weight[i], dp[i - 1][l])
for i in range(N * 300 - 1):
    if dp[-1][i] <= W < dp[-1][i + 1]:
        print(i + 1)
        break
    elif i == N * 300 - 2:
        print(N * 300)
