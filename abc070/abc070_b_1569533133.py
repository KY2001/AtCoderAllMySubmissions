A,B,C,D = map(int,input().split())
if C <= B or D <= A:
    print(0)
elif A <= C <= D <= B:
    print(D-C)
elif C <= A <= B <= D:
    print(B-A)
elif C <= B:
    print(B-C)
else:
    print(D-A)
