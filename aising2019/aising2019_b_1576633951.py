N = int(input())
A, B = map(int, input().split())
P = list(map(int, input().split()))
import sys
for i in range(N):
    for l in range(N-3*i):
        if P[l] <= A:
            del P[l]
            break
        elif l == N-3*i-1:
            print(i)
            sys.exit()
    for l in range(N-3*i-1):
        if A < P[l] <= B:
            del P[l]
            break
        elif l == N-3*i-2:
            print(i)
            sys.exit()
    for l in range(N-3*i-2):
        if B < P[l]:
            del P[l]
            break
        elif l == N-3*i-3:
            print(i)
            sys.exit()
    if not P:
        print(i+1)
        sys.exit()
