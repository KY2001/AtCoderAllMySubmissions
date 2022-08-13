import sys
for i in range(100):
    for l in range(100):
        if 4*i + 7*l == int(input()):
            print("Yes")
            sys.exit()
print("No")