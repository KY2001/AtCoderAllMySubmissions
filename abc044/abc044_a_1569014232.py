N,K,X,Y = map(int,open(0).read().split())
if N >= K:
    print(int((X*K)+(Y*(N-K))))
else:
    print(int(X*N))