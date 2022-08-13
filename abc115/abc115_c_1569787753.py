N, K = map(int,input().split())
h = [int(input()) for _ in range(N)]
h.sort()
m = 10**9
for i in range(N-K+1):
    if h[i+K-1] - h[i] < m:
        m = h[i+K-1] - h[i]
for i in range(N-K+1):
    if h[i+K-1] - h[i] == m:
        print(int(m))
        break
