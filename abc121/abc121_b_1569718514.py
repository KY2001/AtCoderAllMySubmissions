N,M,C = map(int,input().split())
B = list(map(int,input().split()))
A = [list(map(int,input().split())) for _ in range(N)]
t = 0
for s in A:
    if sum([s[i]*B[i] for i in range(M)]) +C > 0:
        t += 1
print(t)
