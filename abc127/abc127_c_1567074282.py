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
    if L[i]>RR or LL>R[i]:
        print(0)
        sys.exit()
    elif LL>=L[i] and RR>=R[i]:
        RR=R[i]
    elif LL>=L[i] and RR<R[i]:
        continue
    elif L[i]>=LL and R[i]>=RR:
        LL = L[i]
    elif L[i]>=LL and R[i]<RR:
        continue
print(RR-LL+1)


