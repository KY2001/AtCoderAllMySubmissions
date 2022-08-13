H,W = map(int,input().split())
a = [list(input()) for _ in range(H)]
while ["." for _ in range(W)] in a:
    a.remove(["." for _ in range(W)])
c = []
for l in range(len(a[0])):
    s = 0
    for i in range(len(a)):
        if a[i][l] == ".":
            s += 1
    if s == len(a):
        c.append(l)
for i in range(len(a)):
    t = 0
    for l in c:
        del a[i][l-t]
        t += 1
for i in range(len(a)):
    print("".join(a[i]))


