ab = int("".join(map(str,input().split())))
if ab**(1/2)%1 == 0:
    print("Yes")
else:
    print("No")
