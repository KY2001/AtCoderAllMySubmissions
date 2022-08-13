N,M = map(int,input().split())
ans = 0
ans2 = 0
t = -3
tt = 0
ps = [tuple(map(str,input().split())) for i in range(M)]
pss = set(sorted(ps))
for i in pss:
    if "AC" in i:
        ans += 1
for i in range(len(ps)):
    if ps[i][1] == "WA":
        t = ps[i][0]
        tt += 1
    if ps[i][0] == t and ps[i][1] == "AC":
        ans2 += tt
        tt = 0
print(ans, ans2)