N = int(input())
m = 0
for _ in range(N):
    x,u = map(str,input().split())
    x = float(x)
    if u == "JPY":
        m += x
    else:
        m += x*380000
print(m)
