N = int(input())
if N%sum(list(str(N))) == 0:
    print("Yes")
else:
    print("No")