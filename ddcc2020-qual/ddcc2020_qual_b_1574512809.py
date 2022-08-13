import sys
N = int(input())
A = list(map(int,input().split()))
Length = sum(A)
SUM = 0
ans = 0
if Length%2 == 0:
    for i in range(N):
        SUM += A[i]
        if SUM == Length / 2:
            print(0)
            sys.exit()
        elif SUM > Length / 2:
            if SUM - Length / 2 <= abs(A[i - 1] - A[i] - Length / 2):
                TT = A[i]
            else:
                TT = A[i - 1]
                SUM -= A[i]
            break
    print(int(2*(abs(SUM - Length/2))))
else:
    Length -= 1
    for i in range(N):
        if A[i] >= 2:
            A[i]-= 1
            c = 1
            break
    for i in range(N):
        SUM += A[i]
        if SUM == Length / 2:
            print(0)
            sys.exit()
        elif SUM > Length / 2:
            if SUM - Length / 2 <= abs(A[i - 1] - A[i] - Length / 2):
                TT = A[i]
            else:
                TT = A[i - 1]
                SUM -= A[i]
            break
    print(int(2*(abs(SUM - Length/2)) + 1))




