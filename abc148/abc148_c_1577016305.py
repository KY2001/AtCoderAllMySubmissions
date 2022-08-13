A, B = map(int,input().split())
import fractions
# 2数を受け取って最小公倍数を返す関数
def lcm(a, b):
    y = a*b / fractions.gcd(a, b)
    return int(y)

print(lcm(A,B))