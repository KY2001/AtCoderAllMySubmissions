N = int(input())
a = [0 for _ in range (10**5)]
for i in range(N):
    l,r = map(int,input().split())
    a[l-1:r+1] = [1]*(r-l+1)
print(sum(a))
