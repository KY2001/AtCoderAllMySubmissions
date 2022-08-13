A, B , K = map(int,input().split())
if K >= A+B:
    print(0, 0)
elif K <= A:
    print(A-K, B)
else:
    print(0,A+B-K)