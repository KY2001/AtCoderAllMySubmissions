N, *a = map(int, open(0).read().split())
aa = sum(a)
r = 0
if aa % N != 0:
    print("-1")
else:
    for i in range(N):
        if a[i] != aa/N:
            s = 0
            for l in range(N-i):
                s += a[i+l]
                if s/(l+1) == aa/N:
                    c = l
                    r += c
                    i += l+1
                    break
    print(r)