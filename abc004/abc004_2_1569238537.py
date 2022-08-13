import copy
c = [(list(map(str,input().split()))) for _ in range(4)]
print(c)
for i in range(4):
    t = copy.deepcopy(c[i])
    for s in range(4):
        c[i][s] = t[-(s+1)]
for i in range(4):
    print(" ".join(c[-(i+1)]))
