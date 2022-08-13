#!usr/bin/env python3

X, Y = map(int, input().split())
if X >= Y:
    print(X - Y)
else:
    ans = 10 ** 18
    for i in range(100):
        ret = i
        gap = abs(X * pow(2, i) - Y)
        for j in range(200):
            if (gap >> j) & 1:
                if j <= i:
                    ret += 1
                else:
                    ret += pow(2, j - i)
        ans = min(ans, ret)
    print(ans)
