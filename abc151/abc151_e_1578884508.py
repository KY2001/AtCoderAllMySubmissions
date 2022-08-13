def power(n, r, mod):
    if r == 0: return 1
    if r % 2 == 0:
        return power(n * n % mod, r // 2, mod) % mod
    if r % 2 == 1:
        return n * power(n, r - 1, mod) % mod


N, K = map(int, input().split())
A = list(map(int, input().split()))
A.sort()
MOD = 10 ** 9 + 7
ans = 0
s = 0
for i in range(1, K - 1):
    s += (A[-i] - A[i - 1])
for i in range(K - 1, N):
    s += (A[-i] - A[i - 1])
    s %= MOD
    ans += (s * power(i - 1, K - 2, MOD)) % MOD
    ans %= MOD
print(int(ans))
