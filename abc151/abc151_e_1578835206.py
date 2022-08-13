from scipy.misc import comb
N, K = map(int,input().split())
A = list(map(int,input().split()))
A.sort()
MOD = 10**9+7
ans = 0
s = 0
for i in range(1, K-1):
    s += (A[-i] - A[i - 1])
for i in range(K-1, N):
    s += (A[-i] - A[i-1])
    s %= MOD
    ans += (s*comb(i-1, K-2))%MOD
    ans %= MOD
print(int(ans))