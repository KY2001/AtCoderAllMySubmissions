N, *a = map(int, open(0).read().split())
aa = sum(a)
r = 0
c = 0
if aa % N != 0:
    print("-1")
else:
    for i in range(N):
        if i < c:
            continue
        elif a[i] != aa/N:
            s = 0
            for l in range(N - i):
                s += a[i + l]
                if s / (l + 1) == aa / N:
                    r += l
                    c += i + l + 1
                    break
    print(r)