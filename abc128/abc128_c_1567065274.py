N,M = map(int,input().split())
s = [list(map(int,input().split()[1:])) for _ in range(M)]
p = list(map(int,input().split()))
ret = 0
for b in range(1 << N):
    if all(sum((b >> (i-1))) & 1 for i in s[j] % 2 == p[j] for j in range(M)):
        ret += 1
print(ret)