import math
a,b,n = map(int,open(0).read().split())
if a != b:
    print(int(a*b*(math.ceil(n/(a*b)))))
else:
    print(int(a*(math.ceil(n/a))))