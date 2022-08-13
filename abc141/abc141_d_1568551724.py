import heapq
import math
N,M = map(int,input().split())
A = list(map(int,input().split()))
A = [-A[_] for _ in range(N)]
heapq.heapify(A)
for i in range(M):
    B = math.ceil(heapq.heappop(A)/2)
    heapq.heappush(A,B)
print(-sum(A))

