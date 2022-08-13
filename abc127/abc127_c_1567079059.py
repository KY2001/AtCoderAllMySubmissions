import sys
N,M = map(int,input().split())
L = []
R = []
for i in range(M):
    a =list(map(int,input().split()))
    L.append(a[0])
    R.append(a[1])
LL = L[0]
RR = R[0]
for i in range(1,M):
    if L[i] > RR or LL > R[i]:
        print(0)
        sys.exit()
    else:
        LL = max(LL, L[i])
        RR = min(RR, R[i])
print(RR - LL + 1)
