N,K = map(int,input().split())
h = list(map(int,input().split()))
s = 0
for i in h:
    if i >= K:
        s += 1
print(s)
