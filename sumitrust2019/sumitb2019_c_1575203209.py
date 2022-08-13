import sys
X = int(input())
if X < 100:
    print(0)
else:
    for i in range(1, 10**3+10):
        if X-100*i < i or X-100*i > 5*i:
            continue
        else:
            print(1)
            sys.exit()
print(0)