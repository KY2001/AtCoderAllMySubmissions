N = int(input())
SP = [list(map(str,input().split())) for _ in range(N)]
for i in range(N):
    SP[i][1] = int(SP[i][1])
for i in range(N):
    SP[i].append(i+1)
SP.sort()
for i in range(N**2):
    for i in range(N-1):
        if SP[i][0] == SP[i + 1][0] and SP[i][1] < SP[i+1][1]:
            A = SP[i]
            SP[i] = SP[i + 1]
            SP[i + 1] = A
for i in range(N):
    print(SP[i][2])
