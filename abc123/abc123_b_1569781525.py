import math
L = list(map(int,open(0).read().split()))
Lm = min([i//10 for i in L])
print(sum([10*math.ceil(i/10) for i in L])-Lm)
import math
L = list(map(int,open(0).read().split()))
Lm = max([10-(i//10) for i in L])
print(sum([10*math.ceil(i/10) for i in L])-Lm)



