N,Q = map(int,input().split())
a = [0 for _ in range(N)]
for i in range(Q):
    L,R,T = map(int,input().split())
    for l in range(R-L+1):
        a[L-1+l] = T
for i in range(N):
    print(a[i])

