N = int(input())
W = list(map(int,input().split()))
a = 9999999999999
for t in range(0,N):
    if abs(sum([W[i] for i in range(t+1)]) -  sum([W[_] for _ in range(t+1,N)])) < a:
        a = abs(sum([W[i] for i in range(t+1)]) -  sum([W[_] for _ in range(t+1,N)]))
print(a)
