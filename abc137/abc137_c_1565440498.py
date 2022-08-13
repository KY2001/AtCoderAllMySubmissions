N = int(input())
S = []
L = 0
for c in range(0,N):
    S.append(str(input()))
    c += 1
for d in range(0,N):
    S[d] = ''.join(sorted(S[d]))
for i in range(0,N):
    for l in range(i+1,N):
        if S[i] == S[l]:
            L += 1
print(L)
