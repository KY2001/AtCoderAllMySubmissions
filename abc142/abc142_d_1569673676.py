A,B = map(int,input().split())
def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a
if A != 1 and B != 1:
    AB = set(prime_factorize(A)) & set(prime_factorize(B))
    print(len(AB)+1)
else:
    print(1)
