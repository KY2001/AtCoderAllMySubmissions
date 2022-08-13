H,W = map(int,input().split())
a = [list(input()) for _ in range(H)]
for i in a:
    if set(i) == {"."}:
        a.remove(i)
aa = [[] for _ in range(W)]
for i in range(len(a)):
    for l in range(W):
        aa[l].append(a[i][l])
for i in aa:
    if set(i) == {"."}:
        aa.remove(i)
b = [[] for _ in range(len(aa[0]))]
for i in range(len(aa)):
    for l in range(len(aa[0])):
        b[l].append(aa[i][l])
for i in b:
    print("".join(i))

