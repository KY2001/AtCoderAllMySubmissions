N = int(input())
S, T = map(str,input().split())
S = list(S)
T = list(T)
P = []
for i in range(N):
    P.append(S[i])
    P.append(T[i])
print("".join(P))