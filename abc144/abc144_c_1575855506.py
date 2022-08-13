import sys
input = sys.stdin.readline
s = 0
N = int(input())
for i in range(1, int(N/2)):
    if N%i == 0 and i > s:
        s = i
print(s+(N//s)-2)