N,X,*m = map(int,open(0).read().split())
m.sort()
X -= sum(m[0:N])
print(N+X//m[0])
