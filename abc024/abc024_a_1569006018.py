A,B,C,K,S,T = map(int,open(0).read().split())
if S+T >= K:
    print(int(T*(B-C)+S*(A-C)))
else:
    print(int(S*A+T*B))
