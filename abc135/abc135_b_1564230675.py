N = int(input())
p = list(map(int,input().split()))
b = 0
for i in range (0,N):
    if p[i] != i+1:
        b += 1
if b <= 2:
    print('YES')
else:
    print('NO')
