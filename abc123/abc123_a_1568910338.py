a,b,c,d,e,k = map(int,open(0).read().split())
if max(e-a) <= k:
    print("Yay!")
else:
    print(":(")