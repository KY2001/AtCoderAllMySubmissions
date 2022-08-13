n,X = map(int,input().split())
a = list(map(int,input().split()))
s = 0
X = list(bin(X))
for i in range(len(X)):
    if X[-(i+1)] == "1":
        s += a[i]
    if X[-(i+1)] == "b":
        break
print(s)

