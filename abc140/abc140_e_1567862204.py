import heapq
N = int(input())
P = list(map(int,input().split()))
sum = 0
heap = []
for L in range(N-1):
    heapq.heappush(heap,-(P[L]))
    for R in range(L+1,N):
        heapq.heappush(heap,-(P[R]))
        S = heapq.heappop(heap)
        sum -= heap[0]
        heapq.heappush(heap,S)
    heap = []
print(sum)



