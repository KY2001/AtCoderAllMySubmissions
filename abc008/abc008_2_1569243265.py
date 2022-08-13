import copy
N = int(input())
S = [input() for _ in range(N)]
SS = list(set(S))
a = 0
b = 0
for i in range(len(SS)):
    for c in range((N)):
        if SS[i] == S[c]:
            a += 1
    if a >= b:
        b = copy.deepcopy(a)
        c = SS[i]
print(c)
