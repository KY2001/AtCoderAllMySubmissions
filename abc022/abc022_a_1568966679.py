N,S,T,W,*A = map(int,open(0).read().split())
s = 0
for i in range(N):
    W += A[i]
    if S <= W <= T :
        s += 1
print(s)