from collections import deque
import copy

H, W = map(int, input().split())
maps2 = deque([deque(["#" for _ in range(W + 2)])])
MAX = 0

for _ in range(H):
    temp = deque(input())
    temp.appendleft("#")
    temp.append("#")
    maps2.append(temp)
maps2.append(deque(["#" for _ in range(W + 2)]))
maps2 = list(maps2)

for i in range(1, H + 1):
    for l in range(1, W + 1):
        maps = copy.deepcopy(maps2)
        if maps2[i][l] != "#":
            pos = [[i, l, 0]]
            while len(pos) > 0:

                y, x, depth = pos.pop(0)
                if depth > MAX:
                    MAX = depth
                maps[y][x] = "$"

                if maps[y + 1][x] == ".":
                    pos.append([y + 1, x, depth + 1])
                if maps[y][x + 1] == ".":
                    pos.append([y, x + 1, depth + 1])
                if maps[y - 1][x] == ".":
                    pos.append([y - 1, x, depth + 1])
                if maps[y][x - 1] == ".":
                    pos.append([y, x - 1, depth + 1])
print(MAX)
