A,B,C = map(int,input().split())
if A>=B:
    if B <= C <= A:
        print("Yes")
    else:
        print("No")
else:
    if A <= C <= B:
        print("Yes")
    else:
        print("No")