N,M = map(int,input().split())
ans = 0
ans2 = 0
ps = [list(map(str,input().split())) for i in range(M)]
ppp = [tuple(i) for i in ps]
pss = set(sorted(ppp))
check = [[0] for i in range(N+1)]
for i in pss:
    if "AC" in i:
        ans += 1
for i in ps:
    i[0] = int(i[0])
for i in range(len(ps)):
    if ps[i][1] == "WA" and check[ps[i][0]] != [-1]:
        check[ps[i][0]][0] += 1
    if ps[i][1] == "AC" and check[ps[i][0]] != [-1]:
        ans2 += check[ps[i][0]][0]
        check[ps[i][0]][0] = -1
print(ans, ans2)