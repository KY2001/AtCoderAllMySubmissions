N, M = map(int, input().split())
xyz = [list(map(int, input().split())) for _ in range(N)]
ans3 = 0
for i in range(2 ** 3):
    ans2 = 0
    xyzSum = []
    ans = [0 for _ in range(N)]
    for l in range(3):
        if (i >> l) & 1 == 0:
            for q in range(N):
                ans[q] += xyz[q][l]
        else:
            a = [-xyz[i][l] for i in range(N)]
            for q in range(N):
                ans[q] -= xyz[q][l]
    ans.sort()
    for q in range(M):
            ans2 += ans[-q-1]
    if ans2 > ans3:
        ans3 = ans2
print(ans3)
