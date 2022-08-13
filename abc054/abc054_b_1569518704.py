import sys
N,M = map(int,input().split())
A = [list(input()) for _ in range(N)]
B = [list(input()) for _ in range(M)]
for i in range(N-M+1):
    for l in range(N - M + 1):
        if A[i][l:l+M] == B[0]:
            for q in range(M):
                if A[i+q][l:l+M] != B[q]:
                    break
                if q == M-1:
                    print("Yes")
                    sys.exit()
print("No")
