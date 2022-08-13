S = int(input())
if S <= 10**9:
    print(0,0,1,0,0,S)
else:
    c = S%(10**9)
    c2 = S//(10**9)
    print(0,0,10**9,(10**9-c),1,c2+1)

