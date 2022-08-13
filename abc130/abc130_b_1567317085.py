import sys
N,X = map(int,input().split())
L = list(map(int,input().split()))
D = 0
i = 0
while D <= X:
    D = (D + L[i])
    i += 1
    if i == N and D <= X:
        print(i+1)
        sys.exit()
print(i)
