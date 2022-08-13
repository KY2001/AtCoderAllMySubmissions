S = list(input())
SS = [S[-i] for i in range(1,len(S)+1)]
s = 0
for i in range(len(S)):
    if S[i] != SS[i]:
        SS[i] = S[i]
        s += 1
print(int(s/2))