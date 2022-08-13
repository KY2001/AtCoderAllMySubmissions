N = int(input())
A = list(map(int,input().split()))
B = 0
C = A[0]
for i in range(0,N):
    B += A[i]
for i in range(1,N):
    C *= A[i]
print(C/(N-1)/B)