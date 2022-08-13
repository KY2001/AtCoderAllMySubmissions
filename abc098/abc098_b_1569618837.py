N = int(input())
S = list(input())
s = 0
for i in range(1,N-1):
    l = set(S[:i]) & set(S[i::])
    if len(l) > s :
        s = len(l)
print(s)
