a = [0,0,1]
for i in range (int(input())-3):
    aa = (a[i]+a[i+1]+a[i+2])%10007
    a.append(aa)
print(a[-1])