a = list(map(int,input().split()))
x1 = a[2]-a[0]
x2 = a[4]-a[0]
y1 = a[3]-a[1]
y2 = a[5]-a[1]
print(abs(x1*y2-x2*y1)/2)