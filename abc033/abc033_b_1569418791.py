N = int(input())
SP = [list(map(str,input().split())) for _ in range(N)]
for i in range(N):
    P = int(SP[i][1])
    SP[i][1] = SP[i][0]
    SP[i][0] = P
PS = sorted(SP)
if 2*PS[-1][0] > sum([PS[i][0] for i in range(N)]):
    print(PS[-1][1])
else:
    print("atcoder")
