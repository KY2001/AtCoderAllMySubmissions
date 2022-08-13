import itertools
N = int(input())
P = tuple(map(int,input().split()))
Q = tuple(map(int,input().split()))

T = list(itertools.permutations(range(1, N+1), N))
for i in range(len(T)):
    if T[i] == P:
        s = i
    if T[i] == Q:
        d = i
print(abs(s-d))