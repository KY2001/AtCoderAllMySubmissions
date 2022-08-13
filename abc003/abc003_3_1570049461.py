N,K = map(int,input().split())
R = list(map(int,input().split()))
R.sort(reverse=True)
C = 0
for i in range(K):
    C = (C+R[K-i-1])/2
print(C)
