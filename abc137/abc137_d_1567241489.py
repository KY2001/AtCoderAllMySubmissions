import heapq
N,M = map(int,input().split())
l = [tuple(map(int,input().split())) for _ in range(N)]
l = sorted(l,reverse=True)
heap = []
ans = 0
for i in range(1,M+1):
        while l and l[-1][0] == i:
            heapq.heappush(heap, -(l.pop()[1]))
        if heap :
            ans -= (heapq.heappop(heap))
print(ans)



