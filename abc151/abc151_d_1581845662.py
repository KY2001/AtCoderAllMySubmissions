import sys
import math
from collections import deque

H, W = map(int, input().split())
maps = deque([deque(["#" for _ in range(W + 2)])])
MAX = 0

for _ in range(H):
    temp = deque(input())
    temp.appendleft("#")
    temp.append("#")
    maps.append(temp)
maps.append(deque(["#" for _ in range(W + 2)]))

for i in range(1, H + 1):
    for l in range(1, W + 1):
        if maps[i][l] == "#":
            break
        else:
            check = [[10 ** 9 for _ in range(W + 2)] for k in range(H + 2)]
            for ab in range(H + 2):
                for bc in range(W + 2):
                    if maps[i][l] == "#":
                        check[i][l] = -1
            pos = [[i, l, 0]]
            while len(pos) > 0:

                y, x, depth = pos.pop(0)
                if depth > MAX:
                    MAX = depth
                if check[y][x] > depth:
                    check[y][x] = depth

                if maps[y + 1][x] != "#" and check[y + 1][x] > depth + 1:
                    pos.append([y + 1, x, depth + 1])
                    check[y + 1][x] = depth + 1
                if maps[y][x + 1] != "#" and check[y][x + 1] > depth + 1:
                    pos.append([y, x + 1, depth + 1])
                    check[y][x + 1] = depth + 1
                if maps[y - 1][x] != "#" and check[y - 1][x] > depth + 1:
                    pos.append([y - 1, x, depth + 1])
                    check[y - 1][x] = depth + 1
                if maps[y][x - 1] != "#" and check[y][x - 1] > depth + 1:
                    pos.append([y, x - 1, depth + 1])
                    check[y][x - 1] = depth + 1
print(MAX)
