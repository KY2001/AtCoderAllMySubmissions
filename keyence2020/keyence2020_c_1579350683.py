import sys
input = sys.stdin.readline
N, K, S = map(int,input().split())
ans = []
for i in range(K):
    ans.append(S)
if S < 10**9:
    for i in range(N-K):
        ans.append(10**9)
else:
    for i in range(N - K):
        ans.append(1)
for i in range(N):
    ans[i] = str(ans[i])
print(" ".join(ans))