D,N = map(int,input().split())
if D != 0 and N != 100:
    print(100**D*N)
elif D != 0 and N == 100:
    print(100**D*101)
elif N == 100:
    print(101)
else:
    print(N)