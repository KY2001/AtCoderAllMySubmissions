n,X,*a = map(int,open(0).read().split())
s = 0
X = list(bin(X))
for i in range(len(X)):
    if X[-(i+1)] == "1":
        s += a[i]
    if X[i+1] == "b":
        break
print(s)

