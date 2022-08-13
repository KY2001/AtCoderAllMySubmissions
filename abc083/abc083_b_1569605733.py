N,A,B = map(int,input().split())
s = 0
for i in range(1,N+1):
    if A <= sum([int(l) for l in list(str(i))]) <= B:
        s += i
print(s)