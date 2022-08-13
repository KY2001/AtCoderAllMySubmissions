N,K = map(int,input().split())
l = sorted(map(int,input().split()),reverse = True)
print(sum([i for i in l[0:K]]))


