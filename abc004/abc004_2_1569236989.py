c = [(list(map(str,input().split()))) for _ in range(4)]
for i in range(4):
    for s in range(4):
        t = c[i]
        c[i][s] = t[-(s+1)]
for i in range(4):
    print(" ".join(c[-(i+1)]))
