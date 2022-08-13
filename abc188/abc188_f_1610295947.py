#!usr/bin/env python3

X, Y = map(int, input().split())
if X >= Y:
    print(X - Y)
else:
    ans = 10 ** 18
    for i in range(100):
        ret = i
        gap = abs(X * pow(2, i) - Y)
        one = 0
        for j in range(200):
            if (gap >> j) & 1:
                if j >= i:
                    ret += pow(2, j - i)
                else:
                    one += 1
        ans = min(ans, ret + min(one, i - one + 2))
    print(ans)
