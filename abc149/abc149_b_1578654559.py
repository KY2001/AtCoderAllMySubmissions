A, B , K = map(int,input().split())
if K >= A &K >= B:
    print(0, 0)
elif K >= A:
    print(0, B-K)
elif K >= B:
    print(A-K, 0)
else:
    print(A-K, B-K)