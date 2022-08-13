N = int(input())
A = list(map(int,input().split()))
B = []
C = 0
for i in range(0,N):
    B.append(1/A[i])
for i in range(0,N):
    C += B[i]
print(1/C)