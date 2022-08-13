N = list(input())
if len(set(N)) <= 2 and N[1] == N[2] and (N[1] == N[0] or N[2] == N[3]):
    print("Yes")
else:
    print("No")
