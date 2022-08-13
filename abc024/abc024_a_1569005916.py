A,B,C,K,S,T = map(int,open(0).read().split())
if S+T >= K:
    print(S*(B-C)+T*(A-C))
else:
    print(S*A+T*B)
    