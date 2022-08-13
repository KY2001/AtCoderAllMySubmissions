N = int(input())
A = list(map(int,input().split()))
B = []
c = 1
for i in range(N):
    if A[i] %2 == 0:
        c *= 2
    else:
        c *= 1
print(3**N-c)