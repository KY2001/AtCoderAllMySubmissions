N = int(input())
c = 0
for i in range(1,N+1):
    a = str(i)
    b = len(a)
    if b % 2 == 1:
        c += 1
print(c)
