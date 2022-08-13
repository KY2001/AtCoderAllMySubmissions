N,K = map(int,input().split())
P = list(map(int,input().split()))
PP = set()
for i in range(N-K+1):
    s = sorted(([P[_] for _ in range(i,i+K)]))
    ss = [P[_] for _ in range(i+K,N)]
    ssss = [P[_] for _ in range(i)]
    sss = tuple(ssss+s+ss)
    if tuple(sss) not in PP:
        PP.add(sss)
print(len(PP))
