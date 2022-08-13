N = int(input())
st = [list(map(str,input().split())) for i in range(N)]
X = input()
ans = 0
for i in range(N):
    if st[i][0] == X:
        for l in range(i+1,N):
            ans += int(st[l][1])
print(ans)
