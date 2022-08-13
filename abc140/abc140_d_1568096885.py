N,K = map(int,input().split())
P = list(input())
count = 0
count2 = 0
for i in range(N-1):
    if P[i] == P[i+1]:
        count2 += 1
if P[0] == 'L':
    for i in range(N - 1):
        if P[i] == 'L' and P[i + 1] == 'R':
            count += 1
    if K == count:
        print(count2 + 2 * K - 1)
    elif K > count:
        print(count2 + 2 * count)
    else:
        print(count2 + 2 * K)
else:
    for i in range(N - 1):
        if P[i] == 'R' and P[i + 1] == 'L':
            count += 1
    if K == count:
        print(count2 + 2 * K - 1)
    elif K > count:
        print(count2 + 2 * count)
    else:
        print(count2 + 2 * K)

       