import bisect
from collections import deque
import sys
input = sys.stdin.readline
N =int(input())
p = 0
XL = [list(map(int,input().split())) for i in range(N)]
ans = []
ans2 = []
for i in range(N):
    ans.append([XL[i][0]-XL[i][1], XL[i][0]+XL[i][1]])
for i in range(N):
    ans2.append([XL[i][0]+XL[i][1], XL[i][0]-XL[i][1]])
t = deque([ans[i][0] for i in range(N)])
tt = deque([ans2[i][0] for i in range(N)])
ans.sort()
ans2.sort()
s = []
for i in range(N-1):
    s.append(bisect.bisect_left(t,ans[i][1])-1)
    t.popleft()
s.append(0)
k = N
for i in range(1, N):
    s[-i] += (k - bisect.bisect_right(tt,ans2[-i][1])-1)
    k -= 1
    tt.pop()
s.sort()
pp = sum(s)
k = N
if pp == 0:
    print(N)
    sys.exit()
for i in range(N):
    pp -= 2*s[-i-1]
    if pp <= 0:
        print(N-i-1)
        break
