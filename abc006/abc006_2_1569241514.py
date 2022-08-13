a = [0,0,1]
n = int(input())
if n >= 4:
    for i in range (n-3):
        aa = (a[i] + a[i + 1] + a[i + 2]) % 10007
        a.append(aa)
else:
    if n == 1:
        print(0)
    elif n == 2:
        print(0)
    else:
        print(1)
print(a[-1])