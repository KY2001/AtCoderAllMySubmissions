N = int(input())
d = list(map(int,input().split()))
sum = 0
for i in range(N):
    for l in range(i+1 ,N):
        sum += d[i]*d[l]
print(sum)



