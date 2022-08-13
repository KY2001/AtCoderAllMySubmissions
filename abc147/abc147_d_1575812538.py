import sys
mod = 10**9+7
N = int(sys.stdin.readline())
A = tuple(map(int, sys.stdin.readline().split()))
B = []
ans = 0
for i in A:
    B.append(list(bin(i)[2:]))
C = [0 for i in range(60)]
for i in B:
    for l in range(len(i)):
        if i[-(l+1)] == '1':
            C[l] += 1
for i in range(60):
    ans = (ans + C[i]*(N-C[i])*(2**i)) % mod
print(ans)