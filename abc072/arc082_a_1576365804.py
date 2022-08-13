N = int(input())
a = list(map(int,input().split()))
a.sort()
p = 1
q = 0
r = 0
ans = 1
p = a[0]
for i in range(N-1):
    if a[i+1] != a[i]:
        r = q
        q = p
        p = 1
    else:
        p += 1
    if p+q+r > ans:
        ans = p+q+r
print(ans)