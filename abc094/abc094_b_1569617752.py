N,M,X = map(int,input().split())
A = set(map(int,input().split()))
Af = [1 for i in range(1,X) if i in A]
Al = [1 for i in range(X+1,N) if i in A]
print(min(sum(Af),sum(Al)))

