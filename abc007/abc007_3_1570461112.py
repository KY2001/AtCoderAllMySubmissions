import sys
R,C = map(int,input().split())
s = list(map(int,input().split()))
g = list(map(int,input().split()))
c = [list(input()) for _ in range(R)]
t = [s]
a = [s]
for i in range(10**6):
    if g in t:
        print(i)
        sys.exit()
    p = []
    for l in t:
        if c[l[0]-1][l[1]] == "." and [l[0],l[1]+1] not in a:
            p.append([l[0],l[1]+1])
        if c[l[0]-1][l[1]-2] == "." and [l[0],l[1]-1] not in a:
            p.append([l[0],l[1]-1])
        if c[l[0]][l[1]-1] == "." and [l[0]+1,l[1]] not in a:
            p.append([l[0]+1,l[1]])
        if c[l[0]-2][l[1]-1] == "." and [l[0]-1,l[1]] not in a:
            p.append([l[0]-1,l[1]])
    a += [w for w in t if w not in a]
    t = p