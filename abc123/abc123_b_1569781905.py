import math
L = [int(input()) for _ in range(5)]
Lm = 10-min([i%10 for i in L if i%10 != 0])
print(sum([10*math.ceil(i/10) for i in L])-Lm)


