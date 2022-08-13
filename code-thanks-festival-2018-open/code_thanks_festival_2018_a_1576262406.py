T,A,B,C,D = map(int,input().split())
if T < A and T < C:
    print(0)
elif T >= A+C:
    print(B+D)
elif T >= C:
    print(D)
else:
    print(B)