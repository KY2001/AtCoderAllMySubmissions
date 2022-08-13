N, M = map(int,input().split())
PYP = [list(map(int,input().split())) for _ in range(M)]
for i in range(M):
    PYP[i].append(i)
PY = sorted(PYP)
P = PY[0][0]
S = 0
for i in range(M):
    if PY[i][0] != P:
        P = PY[i][0]
        S = 0
    S += 1
    PY[i].append(("0"*(6-len(str(P)))+str(P)+"0"*(6-len(str(S)))+str(S)))
for i in PY:
    i[0] = i[2]
PY.sort()
for i in PY:
    print(i[3])
