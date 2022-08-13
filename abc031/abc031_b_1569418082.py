L,H,N,*A = map(int,open(0).read().split())
for i in range(N):
    if A[i] > H:
        print(-1)
    elif A[i] >= L:
        print(0)
    else:
        print(L-A[i])
