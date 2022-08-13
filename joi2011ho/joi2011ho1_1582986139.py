import sys
import math
import fractions
import itertools
from collections import deque
import copy
import bisect
import numpy as np

MOD = 10 ** 9 + 7
INF = 10 ** 18 + 7
input = lambda: sys.stdin.readline().strip()

M, N = map(int, input().split())
K = int(input())
area_info = [input() for _ in range(M)]

j_list = np.zeros((M, N), np.int32)
o_list = np.zeros((M, N), np.int32)
i_list = np.zeros((M, N), np.int32)

a = j_list
for i in range(M):
    for l in range(N):
        if area_info[i][l] == "J":
            a[i][l] = 1
j_list = np.cumsum(np.cumsum(a, axis=1), axis=0)
j_list = np.insert(j_list, M, 0, axis=0)
j_list = np.insert(j_list, M, 0, axis=0)
insert = np.insert(j_list, N, 0, axis=1)
j_list = insert
j_list = np.insert(j_list, N, 0, axis=1)
a = o_list
for i in range(M):
    for l in range(N):
        if area_info[i][l] == "O":
            a[i][l] = 1
o_list = np.cumsum(np.cumsum(a, axis=1), axis=0)
o_list = np.insert(o_list, M, 0, axis=0)
o_list = np.insert(o_list, M, 0, axis=0)
o_list = np.insert(o_list, N, 0, axis=1)
o_list = np.insert(o_list, N, 0, axis=1)
a = i_list
for i in range(M):
    for l in range(N):
        if area_info[i][l] == "I":
            a[i][l] = 1
i_list = np.cumsum(np.cumsum(a, axis=1), axis=0)
i_list = np.insert(i_list, M, 0, axis=0)
i_list = np.insert(i_list, M, 0, axis=0)
i_list = np.insert(i_list, N, 0, axis=1)
i_list = np.insert(i_list, N, 0, axis=1)
for i in range(K):
    a, b, c, d = map(int, input().split())
    print(j_list[c - 1][d - 1] - j_list[c - 1][b - 2] - j_list[a - 2][d - 1] + j_list[a - 2][b - 2],
          o_list[c - 1][d - 1] - o_list[c - 1][b - 2] - o_list[a - 2][d - 1] + o_list[a - 2][b - 2],
          i_list[c - 1][d - 1] - i_list[c - 1][b - 2] - i_list[a - 2][d - 1] + i_list[a - 2][b - 2]
          )
