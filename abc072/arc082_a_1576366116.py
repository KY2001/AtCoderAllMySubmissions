N = int(input())
a = list(map(int,input().split()))
a.sort()
p = 1
q = 0
r = 0
ans = 1
for i in range(N-1):
    if a[i+1] == a[i]+1:
        r = q
        q = p
        p = 1
    elif a[i+1] == a[i]:
        p += 1
    elif a[i+1] == a[i] + 2:
        r = p
        q = 0
        p = 1
    if p+q+r > ans:
        ans = p+q+r
print(ans)