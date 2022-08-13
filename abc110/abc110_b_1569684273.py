import sys
N,M,X,Y = map(int,input().split())
x = list(map(int,input().split()))
y = list(map(int,input().split()))
for i in range(X+1,Y+1):
    if max(x) < i <= min(y):
        print("No War")
        sys.exit()
print("War")
