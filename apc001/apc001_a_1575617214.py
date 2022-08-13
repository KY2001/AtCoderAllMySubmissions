X, Y = map(int,input().split())
if (X/Y)%1 == 0:
    print(-1)
else:
    for i in range(10**6):
        if ((X*i)/Y)%1 != 0:
            print(X*i)
            break