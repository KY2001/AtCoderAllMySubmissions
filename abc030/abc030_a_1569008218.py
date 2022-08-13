A,B,C,D = map(int,input())
Ta = B/A; Ao = D/C
if Ta == Ao:
    print("DRAW")
elif Ta > Ao:
    print("TAKAHASHI")
else:
    print("AOKI")