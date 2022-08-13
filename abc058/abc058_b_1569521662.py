O = list(input())
E = list(input())
ans = ""
for s in range(len(O)+len(E)):
    if s%2 == 0:
        ans += O[0]
        del O[0]
    else:
        ans += E[0]
        del E[0]
print(ans)
