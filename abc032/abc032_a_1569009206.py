a,b,n = map(int,open(0).read().split())
for i in range(10001):
    if (n+i)%a == (n+i)%b == 0:
        print(n+i)
        break