import sys
N = int(input())
for i in range(100):
    for l in range(100):
        if 4*i + 7*l == N:
            print("Yes")
            sys.exit()
print("No")