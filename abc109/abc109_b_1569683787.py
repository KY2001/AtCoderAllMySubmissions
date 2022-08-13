import sys
N,*W = map(str,open().read().split())
N = int(N)
for i in range(N-1):
    if list(N[i])[-1] != list(N[i+1])[0]:
        print("No")
        sys.exit()
print("Yes")