abc = list(map(int,input().split()))
if sum(abc) - 2*max(abc) == 0:
    print("Yes")
else:
    print("No")
