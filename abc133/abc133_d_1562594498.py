N = int(input())
A = list(map(int,input().split()))
B1 = 0
B = []
for i in range(0,N+1):
    if A[i]%2 == 1:
        B1 += A[i]
    else:
        B1 -= A[i]
B.append(B1)
XX = B1
for i in range (0,N-1) :
    X = 2*A[i]-XX
    B.append(X)
    XX = X
print(B)


