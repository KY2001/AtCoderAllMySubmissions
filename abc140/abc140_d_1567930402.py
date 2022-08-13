N,K = map(int,input().split())
P = list(input())
count = 0
for i in range(N-1):
    if P[i] == P[i+1]:
        count += 1
time = 0
for i in range(1,N):
    if P[i] != P[i-1]:
        time += 1
if time == 1:
    print(count + 1)
else:
    print(count + 2*min(K,time))


