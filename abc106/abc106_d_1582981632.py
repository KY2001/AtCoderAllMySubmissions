import sys
import itertools

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()
N, M, Q = map(int, input().split())
sum_list = [[0 for _ in range(N)] for _ in range(N)]
for i in range(M):
    L, R = map(int, input().split())
    sum_list[L - 1][R - 1] += 1
for i in range(N):
    sum_list[i] = list(itertools.accumulate(sum_list[i]))
    sum_list[i].append(0)
for i in range(Q):
    p, q = map(int, input().split())
    ans = 0
    for l in range(p - 1, q):
        ans += sum_list[l][q - 1] - sum_list[l][l - 1]
    print(ans)
