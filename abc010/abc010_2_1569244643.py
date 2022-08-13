n,*a = map(int,open(0).read().split())
c = 0
for i in range(n):
    for l in range(a[i]):
        if a[i] % 2 == 1 and a[i] % 3 != 2:
            break
        else:
            a[i] -= 1
            c += 1
print(c)

