import queue
import sys
R,C = map(int,input().split())
s = list(map(int,input().split()))
g = list(map(int,input().split()))
c = [list(input()) for _ in range(R)]
qqq = queue.Queue()
q = queue.Queue()
q.put(s)
for i in range(100):
    qq = queue.Queue()
    for _ in range(10**6):
        a = q.get()
        if a == g:
            print(i)
            sys.exit()
        if c[a[0] - 2][a[1] - 1] == ".":
            qq.put([a[0]-1, a[1]])
        if c[a[0]][a[1] - 1] == ".":
            qq.put([a[0]+1, a[1]])
        if c[a[0]-1][a[1] - 2] == ".":
            qq.put([a[0], a[1]-1])
        if c[a[0] - 1][a[1]] == ".":
            qq.put([a[0], a[1]+1])
        if q.empty():
            break
    q = qq