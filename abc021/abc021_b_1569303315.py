N,a,b,K,*P = map(int,open(0).read().split())
PP = set(P)
s = 0
if a in PP or b in PP:
    s = 1
else:
    PPP = set()
    for i in P:
        if i not in PPP:
            PPP.add(i)
        else:
            s = 1
if s == 1:
    print("NO")
else:
    print("YES")

