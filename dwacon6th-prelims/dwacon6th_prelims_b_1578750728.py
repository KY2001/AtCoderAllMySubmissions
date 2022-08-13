N = int(input())
x = list(map(int,input().split()))
xx = [x[-i]-x[-i-1] for i in range(1, N)]
xxx = [[] for i in range(N-1)]
xxx[0].append(xx[0])
for i in range(1, N-1):
    for l in range(i):
        xxx[i].append(xxx[i-1][l]+xx[i])
    xxx[i].append(xx[i])
for i in range(N-1):
    xxx[i].reverse()
MOD = 10**9+7
p = 1
for i in range(1, N):
    p *= i
    p %= MOD
S = [[1]]
ans = 0
for i in range(3, N+1):
    t = []
    for l in range(i-3):
        t.append(S[i-3][l])
    t.append(S[i-3][-1]/(i-1))
    t.append(1/(i-1))
    for l in range(i-1):
        ans += xxx[i-2][l]*t[l]
    ans %= MOD
    S.append(t)
ans += xx[0]
print(int((ans*p)%MOD))