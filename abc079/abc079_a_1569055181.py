N = list(input())
if len(set(N)) <= 2 and N[1] == N[2]:
    print("Yes")
else:
    print("No")