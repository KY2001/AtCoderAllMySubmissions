import math
L = [int(input()) for _ in range(5)]
Lm = []
for i in L:
    if i%10 == 0:
        Lm.append(0)
    else:
        Lm.append(10-i%10)
print(sum([10*math.ceil(i/10) for i in L])-max(Lm))



