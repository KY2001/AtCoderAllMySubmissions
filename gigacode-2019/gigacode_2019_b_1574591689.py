N, X, Y, Z = map(int,input().split())
c = 0
for i in range(N):
    A, B = map(int,input().split())
    if A+B >= Z and A >= X and B >= Y:
        c += 1
print(c)
