N = int(input())
V = list(map(int,input().split()))
C = list(map(int,input().split()))
print(sum(V[i] - C[i] for i in range(N) if V[i] - C[i] > 0))