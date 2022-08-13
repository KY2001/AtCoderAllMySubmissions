S = list(input())
N = int(input())
for i in range(N):
    l,r = map(int,input().split())
    SS = S[:]
    for q in range(r-l+1):
        S[l+q-1] = SS[r-1-q]
print("".join(S))

