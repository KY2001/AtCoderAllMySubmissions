import math
import sys
input = sys.stdin.readline
N, D, A = map(int,input().split())
XH = [list(map(int,input().split())) for i in range(N)]
XH.sort()
ans = 0
for i, name in enumerate(XH):
    if name[1] > 0:
        p = name[0]
        t = A*math.ceil(name[1] / A)
        ans += math.ceil(name[1] / A)
        for l in XH[i::]:
            if l[0] <= p + 2 * D:
                l[1] -= t
            else:
                break
print(ans)