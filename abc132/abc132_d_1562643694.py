N,K = map(int,input().split())

for i in range(1,K+1):

    n = N - K + 1
    r = i
    A = [n, r]
    B = 1
    for i in range(1, r + 1):
        C = B * (n - i + 1) / (r - i + 1)
        B = C
    nCr1 = int(B%(10**9+7))

    n = K-1
    r = i-1
    A = [n, r]
    B = 1
    for i in range(1, r + 1):
        C = B * (n - i + 1) / (r - i + 1)
        B = C
    nCr2 = int(B%(10**9+7))
    ZZ =( nCr1 * nCr2 )% (10**9+7)
    print(ZZ)
