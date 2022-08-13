import sys
N,M = map(int,input().split())
for y in range(0,N+1):
    z = (M-2*N-y)/2
    x = N-y-z
    if x >= 0 and z >= 0 and x%1 == 0 and z%1 == 0:
        print(int(x),int(y),int(z))
        sys.exit()
print("-1 -1 -1")

