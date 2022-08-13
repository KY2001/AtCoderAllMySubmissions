import sys
import math
from scipy.misc import comb  # atcoderではspecial→misc, permは使えない

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

N = int(input())
xy = [list(map(int, input().split())) for _ in range(N)]
ans = 0
for i in range(N - 1):
    for l in range(i + 1, N):
        ans += math.sqrt((xy[i][0] - xy[l][0]) ** 2 + (xy[i][1] - xy[l][1]) ** 2)
ans *= (N - 1) / comb(N, 2)
print(ans)
