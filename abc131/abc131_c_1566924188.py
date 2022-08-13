import math
A,B,C,D = [int(i) for i in input().split()]
def lcm(a,b):
    return a*b/math.gcd(a,b)
lcm = lcm(C,D)
aa = ((B//C)-(1 if A%C != 0 else 0))-(A//C)+1
bb = ((B//D)-(1 if A%D != 0 else 0))-(A//D)+1
ll = ((B//lcm)-(1 if A%lcm != 0 else 0))-(A//lcm)+1
print(int((B-A+1)-(aa+bb-ll)))
