N = int(input())
K = int(input())
M = 1
for _ in range(N):
    M = min(M+K,M*2)
print(M)