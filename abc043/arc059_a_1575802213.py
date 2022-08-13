N = int(input())
a = list(map(int,input().split()))
c = []
for i in range(-100,101):
    s = 0
    for l in range(N):
        s += (a[l]-i)**2
    c.append(s)
print(min(c))


