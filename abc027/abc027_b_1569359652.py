N,*a = map(int,open(0).read().split())
r = 0
s = 0
if sum(a)%N != 0:
    print("-1")
else:
    for i in range(N):
        if sum(a[0:i + 1]) != (i + 1) * (sum(a) / N):
            s += 1
    print(s)
