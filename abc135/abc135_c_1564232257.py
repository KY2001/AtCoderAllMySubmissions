N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
C = 0
if A[0] > B[0]:
    C += B[0]
    B[0] = 0
else:
    B[0] = (B[0] - A[0])
    C += A[0]
for i in range(1,N):
    if A[i] > (B[i-1]+B[i]):
         C += (B[i - 1] + B[i])
         B[i] = 0
    else:
        B[i] = B[i]-(A[i]-B[i-1])
        C += A[i]
if A[N] > B[N-1]:
    C += B[N-1]
else:
    C += A[N]
print(C)

