N = int(input())
L = [str(l) for l in list(range(1,7))]
for i in range(N):
    S = L[i%5]
    L[i%5] = L[i%5+1]
    L[i%5+1] = S
print("".join(L))

