N = int(input())
import sys
H = [int(i) for i in input().split()]
if N == 1:
    print('Yes')
    sys.exit()
for i in (N-1,2,-1):
    if H[i]+1 < H[i-1]:
        print('No')
        sys.exit()
    elif H[i] < H[i-1]:
        H[i-1] -= 1
    else:
        continue
print('Yes')
