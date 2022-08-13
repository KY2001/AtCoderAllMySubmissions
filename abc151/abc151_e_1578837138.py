N, K = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
MOD = 10 ** 9 + 7
ans = 0
s = 0
t = 1
if K == 1:
    print(0)
else:
    for i in range(1, K - 1):
        s += (A[-i] - A[i - 1])
    for i in range(K - 1, N):
        s += (A[-i] - A[i - 1])
        s %= MOD
        if (i + 1 - K) > 0:
            t *= (i - 1)
            t /= (i + 1 - K)
        ans += (s * t) % MOD
        ans %= MOD
    print(int(ans))
