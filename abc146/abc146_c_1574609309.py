A, B, X = map(int, input().split())
if A+B > X:
    print(0)
else:
    for i in range(1, 1000):
        d = (X-(i*B))//A
        if d == 10**i:
            d -= 1
            if 10**(i-1) <= d < 10**i:
                if d >= 10 ** 9:
                    print(int(10 ** 9))
                else:
                    print(int(d))
                break
        elif 10**(i-1) <= (X-(i*B))/A < 10**i:
            if ((X-(i*B))//A) >= 10**9:
                print(int(10**9))
            else:
                print(int(((X-i*B)//A)))
            break