N,A,B = map(int,input().split())
print(min(A,B))
if A+B <= N:
    print(0)
else:
    print(A+B-N)