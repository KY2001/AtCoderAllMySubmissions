D = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
SUMa = sum(a)
money = 0
for i in range(D):
    money += a[i]
    if money >= b[i]:
        bb = b[i]
        for l in range(i, D):
            if b[l] <= bb:
                bb = b[l]
        break
    elif i == D-1:
        bb = -1
print(bb)