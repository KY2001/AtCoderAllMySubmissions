import math
A,B,C,D = [int(i) for i in input().split()]
ii = 1
ee = 1
dd = 0
for i in range(A,B+1):
    if i % C == 0:
        z = i
        break
for i in range(A,B+1):
    if i % D == 0:
        v = i
        break
rr = z
while rr < B:
    rr += C
    ii += 1
ll = v
while ll < B:
    ll += C
    ee += 1
    if ll % (C*D) == 0:
        dd += 1
print(int((B-A+4)-(ii+ee-dd)))


