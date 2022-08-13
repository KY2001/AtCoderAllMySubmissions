N = int(input())
L = [str(l) for l in list(range(1, 7))]
I = 10**10
for i in range(10**10):
    S = L[i % 5]
    L[i % 5] = L[i % 5 + 1]
    L[i % 5 + 1] = S
    if L == [str(l) for l in list(range(1, 7))]:
        I = i+1
        break
L = [str(l) for l in list(range(1, 7))]
for i in range(N%I):
    S = L[i % 5]
    L[i % 5] = L[i % 5 + 1]
    L[i % 5 + 1] = S
    if L == [str(l) for l in list(range(1, 7))]:
        I = i+1
print("".join(L))
