import sys
input = sys.stdin.readline

N = int(input())
s = 1
S = list(input())
for i in range(N-1):
    if S[i+1] != S[i]:
        s += 1
    else:
        continue
print(s)