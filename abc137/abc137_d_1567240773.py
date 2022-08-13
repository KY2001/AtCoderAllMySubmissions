import heapq
N,M = map(int,input().split())
l = [tuple(map(int,input().split())) for _ in range(N)]
l = sorted(l)
heap = []
a = 0
b = 0
for i in range(1,M+1):
        while l and l[a][0] <= i:
            heapq.heappush(heap, -(l[a][1]))
        if heap :
            b -= (heapq.heappop(heap))
print(b)
