import math
N,*A = map(int,open(0).read().split())
n = 0
s = 0
for i in A:
    if A == 0:
        continue
    else:
        n += 1
        s += i
print(math.ceil(s/n))


