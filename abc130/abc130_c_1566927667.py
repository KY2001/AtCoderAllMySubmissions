W,H,a,b =[int(i) for i in input().split()]
if a == W or b == H:
    r = 0
elif a/W == b/H:
    r = 1
else :
    r = 0
print((W*H)/2,int(r))
