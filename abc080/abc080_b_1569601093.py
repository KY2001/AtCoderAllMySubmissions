N = int(input())
if N % sum([int(i) for i in list(str(N))]) == 0:
    print("Yes")
else:
    print("No")