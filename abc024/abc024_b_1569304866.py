N,T,*A = map(int,open(0).read().split())
t = 0
for i in range(N-1):
    if A[i+1] - A[i] < T:
        t += A[i+1] - A[i]
    else:
        t += T
print(t+T)
