import sys
mod = 10**9+7
N = int(sys.stdin.readline())
A = tuple(map(int, sys.stdin.readline().split()))
B = []
ans = 0
C = [0 for i in range(60)]
for i in A:
    for l in range(60):
        if ((i >> l) & 1) == 1:
            C[l] += 1
for i in range(60):
    t = C[i]
    ans = (ans + t*(N-t)*(2**i)) % mod
print(ans)