A, B , K = map(int,input().split())
for i in range(K):
    if A >= 1:
        A-= 1
    if B>= 1:
        B-=1
print(A,B)