N,*a = map(int,open(0).read().split())
a.sort(reverse=True)
al = 0
b = 0
for i in range(N):
    if i%2 == 0:
        al += a[0]
        del a[0]
    else:
        b += a[0]
        del a[0]
print(al-b)