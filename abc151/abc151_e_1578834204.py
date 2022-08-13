import scipy.special
N, K = map(int,input().split())
A = list(map(int,input().split()))
A.sort()
MOD = 10**9+7
ans = 0
s = 0
for i in range(1, N):
    s += (A[-i] - A[i-1])
    s %= MOD
    ans += (s*(scipy.special.comb(i-1, K-2)%MOD))%MOD
    ans %= MOD
print(int(ans))