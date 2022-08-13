from decimal import Decimal, ROUND_HALF_UP, ROUND_HALF_EVEN
Deg, Dis = map(int,input().split())
Dis = Decimal(str(Dis/60)).quantize(Decimal("0.1"), rounding=ROUND_HALF_UP)
Deg /= 10
C = [[0,0.2],[0.3,1.5],[1.6,3.3],[3.4,5.4],[5.5,7.9],[8,10.7],[10.8,13.8],[13.9,17.1],[17.2,20.7],[20.8,24.4],[24.5,28.4],[28.5,32.6],[32.7,10**9]]
for i in range(len(C)):
    if C[i][0] <= float(str(Dis)) <= C[i][1]:
        W = i
C2 = [[11.25 + 22.5*i,11.25 + 22.5*(i+1)] for i in range(15)]
C2.insert(0,[0,11.25])
C2.append([348.75,360])
C2ex = ["N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW","N"]
for i in range(len(C2)):
    if C2[i][0] <= Deg < C2[i][1]:
        Dir = C2ex[i]
if W != 0:
    print(Dir,W)
else:
    print("C", 0)