import sys
input = sys.stdin.readline
s = 0
N = int(input())
for i in range(1, 10**6):
    if N%i == 0 and i > s and i != N:
        s = i
print(s+(N//s)-2)