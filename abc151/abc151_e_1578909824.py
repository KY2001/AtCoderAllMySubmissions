N, K = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
MOD = 10 ** 9 + 7
ans = 0
s = 0
nCk = 1
for i in range(1, K - 1):
    s += (A[-i] - A[i - 1])
for i in range(K - 1, N):
    s += (A[-i] - A[i - 1])
    s %= MOD
    if i >= K:
        nCk *= (i-1)
        nCk /= (i-K+1)
        nCk %= MOD
    ans += (s * nCk) % MOD
    ans %= MOD
print(int(ans))
