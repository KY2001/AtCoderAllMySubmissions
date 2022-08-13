N = int(input())
T,A = map(int,input().split())
H = list(map(int,input().split()))
TH = [[abs(T-H[i]*0.006-A),(i+1)] for i in range(N)]
TH.sort()
print(TH[0][1])

