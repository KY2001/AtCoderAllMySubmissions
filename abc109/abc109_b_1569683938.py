import sys
N,*W = map(str,open(0).read().split())
N = int(N)
for i in range(N-1):
    if list(W[i])[-1] != list(W[i+1])[0]:
        print("No")
        sys.exit()
if len(W) != len(set(W)):
    print("No")
    sys.exit()
print("Yes")