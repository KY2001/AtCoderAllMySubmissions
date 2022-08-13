import sys
txa, tya, txb, tyb, T,V = map(int,input().split())
n = int(input())
xy = [list(map(int,input().split())) for i in range(n)]
for i in range(n):
    if ((xy[i][0]-txa)**2+(xy[i][1]-tya)**2)**(1/2)+((xy[i][0]-txb)**2+(xy[i][1]-tyb)**2)**(1/2) <= (V*T):
        print("YES")
        sys.exit()
print("NO")