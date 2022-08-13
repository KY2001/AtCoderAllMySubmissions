W,H,a,b =[int(i) for i in input().split()]
if (a,b) == (W,H):
    r = 1
else:
    r = 0
print((W*H)/2,int(r))
