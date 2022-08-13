N = int(input())
T = list(map(int,input().split()))
M = int(input())
TT = sum(T)
PT = [list(map(int,input().split())) for _ in range(M)]
for i in range(M):
    P = PT[i][0]
    TTT = PT[i][1]
    print(TT-(T[P-1]-TTT))