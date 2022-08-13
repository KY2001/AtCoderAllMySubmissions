import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

M, N = map(int, input().split())
K = int(input())
area_info = [input() for _ in range(M)]

j_list = [[0 for _ in range(N)] for _ in range(M)]
o_list = [[0 for _ in range(N)] for _ in range(M)]
i_list = [[0 for _ in range(N)] for _ in range(M)]

a = j_list
for i in range(M):
    for l in range(N):
        if l == 0:
            if area_info[i][0] == "J":
                a[i][0] = 1
        else:
            if area_info[i][l] == "J":
                a[i][l] = a[i][l - 1] + 1
            else:
                a[i][l] = a[i][l - 1]
for l in range(N):
    for i in range(1, M):
        a[i][l] += a[i - 1][l]
a = o_list
for i in range(M):
    for l in range(N):
        if l == 0:
            if area_info[i][0] == "O":
                a[i][0] = 1
        else:
            if area_info[i][l] == "O":
                a[i][l] = a[i][l - 1] + 1
            else:
                a[i][l] = a[i][l - 1]
for l in range(N):
    for i in range(1, M):
        a[i][l] += a[i - 1][l]
a = i_list
for i in range(M):
    for l in range(N):
        if l == 0:
            if area_info[i][0] == "I":
                a[i][0] = 1
        else:
            if area_info[i][l] == "I":
                a[i][l] = a[i][l - 1] + 1
            else:
                a[i][l] = a[i][l - 1]
for l in range(N):
    for i in range(1, M):
        a[i][l] += a[i - 1][l]
for i in range(K):
    a, b, c, d = map(int, input().split())
    if a < 2 and b < 2:
        print(j_list[c - 1][d - 1], o_list[c - 1][d - 1], i_list[c - 1][d - 1])
    elif a < 2:
        print(j_list[c - 1][d - 1] - j_list[c - 1][b - 2], o_list[c - 1][d - 1] - o_list[c - 1][b - 2],
              i_list[c - 1][d - 1] - i_list[c - 1][b - 2])
    elif b < 2:
        print(j_list[c - 1][d - 1] - j_list[a - 2][d - 1], o_list[c - 1][d - 1] - o_list[a - 2][d - 1],
              i_list[c - 1][d - 1] - i_list[a - 2][d - 1]
              )
    else:
        print(j_list[c - 1][d - 1] - j_list[c - 1][b - 2] - j_list[a - 2][d - 1] + j_list[a - 2][b - 2],
              o_list[c - 1][d - 1] - o_list[c - 1][b - 2] - o_list[a - 2][d - 1] + o_list[a - 2][b - 2],
              i_list[c - 1][d - 1] - i_list[c - 1][b - 2] - i_list[a - 2][d - 1] + i_list[a - 2][b - 2]
              )
