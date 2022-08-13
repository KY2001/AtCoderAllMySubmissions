n,L = map(int,input().split())
N=0
G=0
for i in range(1,n):
    N +=(i+L-1)
NN = N
for i in range(1,n):
        DD = NN - (L+i-1)
        if DD>G :
            G = DD
print(G)
    