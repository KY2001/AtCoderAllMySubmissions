import sys
N = int(input())
a = [int(input()) for _ in range(N)]
s = 1
for i in range(N):
    if s == 2:
        print(i)
        sys.exit()
    s = a[s-1]
print(-1)

