N,M = map(int,input().split())
ab = [list(map(int,input().split())) for _ in range(N)]
cd = [list(map(int,input().split())) for _ in range(M)]
m = 10**9
for i in range(N):
    for l in range(M):
        c = abs(ab[i][0]-cd[l][0])+abs(ab[i][1]-(cd[l][1]))
        if c < m :
            m = c
            t = l+1
    print(t)
    m = 10**9