N,*S = map(int,open(0).read().split())
SS = list(set(S))
a = 0
b = 0
for i in range(len(SS)):
    for c in range(len(S)):
        if SS[i] == S[c]:
            a += 1
    if a > b:
        b = a
        c = SS[i]
print(c)
