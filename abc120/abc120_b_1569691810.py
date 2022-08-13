A,B,K = map(int,input().split())
c = []
for i in range(1,101):
    if A%i == B%i == 0:
        c.append(i)
print(sorted(c)[-K])

