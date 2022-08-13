import sys
import math
from collections import deque
import copy

N, K = map(int, input().split())

s = [int(input()) for _ in range(N)]
ans = 0
ss = []
for k in range(N):
    if s[k] == 0:
        SUM = 1
        right = 0
        p = 0
        for i in range(len(ss)):
            if p == 1:
                break
            while True:
                SUM *= ss[right]
                if SUM > K:
                    SUM /= ss[i]
                    SUM /= ss[right]
                    break
                if right - i + 1 >= ans:
                    ans = right - i + 1
                right += 1
                if right >= len(ss):
                    p = 1
                    break
        if ans < N:
            ans = N
        ss = []
    elif len(ss) == N - 1:
        ss.append(s[k])
        SUM = 1
        right = 0
        p = 0
        for i in range(len(ss)):
            if p == 1:
                break
            while True:
                SUM *= ss[right]
                if SUM > K:
                    SUM /= ss[i]
                    SUM /= ss[right]
                    break
                if right - i + 1 >= ans:
                    ans = right - i + 1
                right += 1
                if right >= len(ss):
                    p = 1
                    break
    else:
        ss.append(s[k])
print(ans)
