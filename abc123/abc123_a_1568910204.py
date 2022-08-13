a,b,c,d,e,k = map(int,open(0).read().split())
if max(b-a,c-b,d-c,e-d) <= k:
    print(":(")
else:
    print("Yay!")
