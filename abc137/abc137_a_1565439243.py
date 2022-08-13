A,B = map(int,input().split())
S = A+B
L = A-B
Z = A*B
if S>L and S>Z :
    print(S)
elif L>S and L>Z:
    print(L)
else:
    print(Z)