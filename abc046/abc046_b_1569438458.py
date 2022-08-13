N,K = map(int,input().split())
ss = K
for i in range(N-1):
    ss *= (K-1)
print(ss)