n,x,*l=map(int,open(0).read().split())
print(sum(x>=sum(l[:i+1])for i in range(n))+1)

