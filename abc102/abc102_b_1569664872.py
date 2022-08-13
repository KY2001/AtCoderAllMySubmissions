N,*A = map(int,open(0).read().split())
A.sort()
print(abs(A[-1]-A[0]))