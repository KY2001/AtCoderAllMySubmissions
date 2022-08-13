import sys
N, M = map(int, input().split())
X = list(map(int,input().split()))
X.sort()
dis = []
if N-1 >= M-1:
    print(0)
    sys.exit()
for i in range(M-1):
    dis.append(abs(X[i+1]-X[i]))
dis.sort()
for i in range(N-1):
    del dis[-1]
print(sum(dis))