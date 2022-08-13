import sys
X = int(input())
P = [2]
if X == 2:
    print(2)

    sys.exit()
for i in range(3, 10**6):
    for l in range(len(P)):
        if i % P[l] == 0:
            break
        elif l == len(P)-1 and i >= X:
            print(i)
            sys.exit()
        elif l == len(P)-1:
            P.append(i)
