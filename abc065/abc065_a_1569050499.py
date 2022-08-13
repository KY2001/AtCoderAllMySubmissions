X,A,B = map(int,input().split())
if B-A > X:
    print("dangerous")
elif B-A <= 0:
    print("delicious")
else:
    print("safe")