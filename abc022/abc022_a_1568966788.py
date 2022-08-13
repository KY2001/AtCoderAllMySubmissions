N,S,T,W,*A = map(int,open(0).read().split())
s = 0
for i in range(N-1):
    if S <= W <= T :
        s += 1
    W += A[i]
    if i == N-2:
        if S <= W <= T:
            s += 1     
print(s)
