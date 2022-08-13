#!usr/bin/env python3

import sys

import math

import string

import collections

import fractions

import random

from operator import itemgetter

import itertools

from collections import deque

import copy

import heapq

import bisect

MOD = 10 ** 9 + 7

INF = float('inf')

input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)
H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]
S_ove = []
S_gold = []
for i in range(H):
    S_ove.append(list(itertools.accumulate([1 if S[i][j] == "O" else 0 for j in range(W)])) + [0])
for i in range(W):
    S_gold.append(list(itertools.accumulate([1 if S[j][i] == "I" else 0 for j in range(H)])) + [0])
ans = 0
for i in range(H):
    for j in range(W):
        if S[i][j] == "J":
            ans += (S_ove[i][-2] - S_ove[i][j - 1]) * (S_gold[j][-2] - S_gold[j][i - 1])

print(ans)