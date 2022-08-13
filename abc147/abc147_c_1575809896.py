N = int(input())
xy = []
for i in range(N):
    t = []
    A = int(input())
    for l in range(A):
        t.append(list(map(int,input().split())))
    xy.append(t)
ans = 0
for i in range(2**N):
    p = []
    for l in range(N):
        if ((i >> l) & 1) == 1:
            p.append(1)
        else:
            p.append(0)
    c = 0
    if sum(p) > ans:
        for l in range(N):
            if p[l] != 0:
                for j in xy[l]:
                    if p[j[0] - 1] != j[1]:
                        c = 1
        if c == 0 and p != [1,1,1]:
            ans = sum(p)
print(ans)