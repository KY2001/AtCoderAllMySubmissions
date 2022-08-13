X = int(input())
import sys
if X < 100:
    print(0)
else:
    for i in range(10**3):
        if X-100*i < i or X-100*i > 5*i:
            continue
        else:
            print(1)
            sys.exit()
print(0)