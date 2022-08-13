N,M = map(int,input().split())
K = [list(map(int,input().split()))[1:] for _ in range(N)]
t = 0
for i in range(1,M+1):
    s = 0
    for l in K:
        if i in l:
            s += 1
    if s == N:
        t += 1
print(t)



