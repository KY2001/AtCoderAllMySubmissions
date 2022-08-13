N = int(input())
a = list(map(int,input().split()))
aa = set(a)
if 1 not in aa:
    print("-1")
else:
    p = 1
    for i in a:
        if i == p:
            p += 1
    print(N-p+1)
