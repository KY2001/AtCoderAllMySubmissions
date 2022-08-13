import sys
import copy
input = sys.stdin.readline
N = int(input())
ans = 0
xy = [list(map(int, input().split())) for i in range(N)]


def maken(n):
    s = 1
    for i in range(1, n+1):
        s *= i
    return s


for i in range(N):
    xy2 = copy.deepcopy(xy)
    c = xy2[i]
    del xy2[i]
    for l in xy2:
        ans += (((c[0]-l[0])**2+(c[1]-l[1])**2)**(1/2))*(maken(N-1))
print(ans/maken(N))