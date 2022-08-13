N = int(input())
A = list(map(int,input().split()))
AA = [[A[i],i+1] for i in range(N) ]
AA.sort()
B = [str(i[1]) for i in AA]
print(" ".join(B))