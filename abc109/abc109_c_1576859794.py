import fractions

N, X = map(int, input().split())
x = list(map(int, input().split()))
x = [i - X for i in x]

ans = x[0]
for i in range(N):
    ans = fractions.gcd(ans, x[i])
print(abs(ans))
