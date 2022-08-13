N = int(input())
v = list(map(int,input().split()))
v.sort()
for i in range(1,N):
    v.sort()
    v[0] = (v[0]+v[1])/2
    del v[1]
print(v[0])