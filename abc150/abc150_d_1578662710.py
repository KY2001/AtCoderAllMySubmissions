import sys
import fractions
N, M = map(int,input().split())
a = list(map(int,input().split()))
b = sorted([i/2 for i in a])
bb = set(b)
bb = list(b)
ans = bb[0]
for i in range(1, N):
    ans = ans * bb[i] // fractions.gcd(ans, bb[i])
if b[0]%2 == 0:
    for i in b:
        if i%2 == 1:
            print(0)
            sys.exit()
    bmin = min(b)
    bmax = max(b)
    print(int(((M+bmin-bmax)/ans)/2+1))
elif  b[0]%2 == 1:
    for i in b:
        if i%2 == 0:
            print(0)
            sys.exit()
    bmin = min(b)
    bmax = max(b)
    print(int((M + bmin - bmax) / 2/ans + 1))
