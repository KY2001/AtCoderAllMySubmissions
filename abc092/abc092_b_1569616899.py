N = int(input())
D,X = map(int,input().split())
A = [int(input()) for _ in range(N)]
S = [1 for i in A for s in range(D) if (i*s+1) <= D ]
print(sum(S)+X)
