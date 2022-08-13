import math
N,K = map(int,input().split())
S = list(input())
SS = sorted(S)
c = 0
ccc = 0
for i in range(N):
    if S[i] != SS[i]:
        c += 1
if c <= K:
    print("".join(SS))
else:
    for i in range(math.ceil(K/2)):
        ccc = 0
        for l in range(N):
            if S[l] != SS[l]:
                for q in range(N-1,-1,-1):
                    if S[q] == SS[l]:
                        S[q] = S[l]
                        S[l] = SS[l]
                        ccc = 1
            if ccc == 1:
                break
    print("".join(S))



