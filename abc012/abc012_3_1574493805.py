N = int(input())
SUM = sum([i for i in range(1,10)])**2
ans = SUM-N
for i in range(1,10):
    for l in range(1,10):
        if i*l == ans:
            print(str(i)+" x "+str(l))
