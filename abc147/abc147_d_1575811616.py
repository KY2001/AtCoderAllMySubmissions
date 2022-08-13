N = int(input())
A = list(map(int,input().split()))
B = []
ans = 0
for i in A:
    B.append(list(bin(i)[2:]))
for i in range (len(B)):
    for l in range(len(B[i])):
        B[i][l] = int(B[i][l])
C = [0 for i in range(60)]
for i in B:
    for l in range(len(i)):
        if i[-(l+1)] == 1:
            C[l] += 1
for i in range(60):
    ans = (ans + C[i]*(N-C[i])*(2**i))%(10**9+7)
print(ans)