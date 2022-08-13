A, B, X = map(int,input().split())
if A+B > X:
    print(0)
else:
    for i in range(1, 1000):
        if 10**(i-1) <= (X-(i*B))//A < 10**i:
            if ((X-(i*B))//A) > 10**9:
                print(int(1000000000))
            else:
                print(int(((X-i*B)//A)))
            break