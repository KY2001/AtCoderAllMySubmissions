N,K,M = map(int,input().split())
A = list(map(int,input().split()))
if (sum(A)+K)/N < M:
    print(-1)
else:
    for i in range(K+1):
        if (sum(A)+i)/N >= M:
            print(i)
            break