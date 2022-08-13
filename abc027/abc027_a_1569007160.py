A = list(map(int,input().split()))
if len(set(A)) == 1:
    print(A[0])
else:
    print(2*sum(set(A))-sum(A))