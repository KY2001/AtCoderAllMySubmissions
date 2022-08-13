N = int(input())
s = [list(input()) for _ in range(N)]
ss = [[] for _ in range(N)]
for i in range(N):
    for l in range(N):
        ss[l].append(s[(-(i+1))][l])
for i in range(N):
    print("".join(ss[i]))
