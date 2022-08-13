import math
N,R = map(int,open(0).read().split())
s = 0
for i in range(N):
    if i%2 == 1:
        s -= math.pi*(R[i]**2)
    else:
        s += math.pi*(R[i]**2)
print(s)