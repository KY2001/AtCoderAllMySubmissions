import copy
N = int(input())
S = [input() for _ in range(N)]
SS = list(set(S))
a = 0
b = 0
c = S[0]
for i in range(len(SS)):
    for p in range(N):
        if SS[i] == S[p]:
            a += 1
    if a >= b:
        b = a
        c = SS[i]
    a = 0
print(c)
