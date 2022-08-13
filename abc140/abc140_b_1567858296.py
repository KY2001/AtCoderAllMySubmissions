N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
C = list(map(int,input().split()))
SUM = 0
for i in range(N):
    SUM += B[A[i]-1]
    if i >= 1 and A[i] == (A[i-1]+1):
        SUM += C[A[i-1]-1]
print(SUM)
