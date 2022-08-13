import sys
N = int(input())
txy2 = [list(map(int,input().split())) for _ in range(N)]
txy = [[0,0,0]]
for i in range(N):
    txy.append(txy2[i])
for i in range(N):
    if abs(txy[i+1][1]-txy[i][1])+abs(txy[i+1][2]-txy[i][2]) > txy[i+1][0]-txy[i][0]:
        print("No")
        sys.exit()
    elif ((txy[i+1][0]-txy[i][0]) - (abs(txy[i+1][1]-txy[i][1])+abs(txy[i+1][2]-txy[i][2])))%2 != 0:
        print("No")
        sys.exit()