import heapq
N = int(input())
P = list(map(int,input().split()))
sum = 0
heap = []
for L in range(N-1):
    heapq.heappush(heap,-(P[L]))
    for R in range(L+1,N):
        heapq.heappush(heap,-(P[R]))
        heap.sort()
        sum -= heap[1]
    heap = []
print(sum)


