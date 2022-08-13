import sys

N, K = map(int, input().split())
x = list(map(int, input().split()))
ans = abs(x[0])
if N == 1:
    print(abs(x[0]))
    sys.exit()
for i in range(N - 1):
    if x[i] < 0 and x[i + 1] >= 0:
        c = i
        break
    elif i == N - 2 and x[0] >= 0:
        for l in range(K - 1):
            ans += (x[i + 1] - x[i])
        print(ans)
        sys.exit()
    elif i == N - 2 and x[0] < 0:
        for l in range(K - 1):
            ans += abs(x[i + 1] - x[i])
        print(ans)
        sys.exit()
ans = abs(x[c])
for i in range(c - K + 1, c):
    ans += abs(x[i] - x[i + 1])
ANS = ans
for i in range(K - 1):
    ans -= abs(x[c - K + 1 + i] - x[c - K + 2 + i])
    ans += abs(x[c + i] - x[c + i + 1])
    if ANS > ans:
        ANS = ans
print(ANS)
