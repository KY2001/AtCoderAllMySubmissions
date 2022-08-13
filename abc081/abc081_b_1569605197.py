N = int(input())
A = list(map(int,input().split()))
for i in range(10**9):
    A = [l//2 for l in A if l//2 == l/2 ]
    if len(A) != N:
        print(i)
        break