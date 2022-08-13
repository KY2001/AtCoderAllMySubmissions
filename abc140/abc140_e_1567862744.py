N = int(input())
P = list(map(int,input().split()))
sum = 0
for L in range(N-1):
    S = sorted([P[L],P[L+1]])
    sum += S[0]
    for R in range(L+2,N):
        if P[R] > S[1]:
            S[0] = S[1]
            S[1] = P[R]
        elif P[R] > S[0]:
            S[0] = P[R]
        sum += S[0]
print(sum)



