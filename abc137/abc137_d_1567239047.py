import heapq
N,M = map(int,input().split())
l = [list(map(int,input().split())) for _ in range(N)]
l = sorted(l)
heap = []
a = 0
b = 0
for i in range(1,M+1):
    while l[a][0] <= i:
        a = 0
        heapq.heappush(heap,-(l[a][1]))
        a += 1
    if heap == []:
        continue
    else:
        b += -(heapq.heappop(heap))
print(b)




