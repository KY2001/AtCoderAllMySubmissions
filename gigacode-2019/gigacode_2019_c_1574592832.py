D = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
SUMa = sum(a)
money = 0
if b[-1] > SUMa:
    print(-1)
else:
    for i in range(D):
        money += a[i]
        if money >= b[i]:
            bb = b[i]
            for l in range(i, D):
                if b[l] <= bb:
                    bb = b[l]
            break
    print(bb)