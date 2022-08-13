import math
N = int(input())
A = list(map(int,input().split()))
n = 0
s = 0
for i in A:
    if i == 0:
        continue
    else:
        n += 1
        s += i
print(math.ceil(s/n))


