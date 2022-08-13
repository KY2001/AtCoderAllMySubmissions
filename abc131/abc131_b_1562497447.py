n, L = map(int, input().split())
N = 0
G = 999
for i in range(1, n+1):
    N += (i + L - 1)
NN = N
for i in range(1, n+1):
    DD = NN - (L + i - 1)
    if abs(NN-DD)< G :
        G = abs(NN-DD)
        ZZ = DD
print(ZZ)