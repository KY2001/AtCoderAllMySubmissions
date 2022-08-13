D, N = map(int,input().split())
s = 0
if N != 100:
    print(100**D*N)
else:
    print(100*D*(N+1))
