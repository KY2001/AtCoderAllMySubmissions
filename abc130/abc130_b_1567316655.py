N,X = map(int,input().split())
L = list(map(int,input().split()))
D = 0
i = 0
while D <= X:
    D = (D + L[i])
    i += 1
print(i)
