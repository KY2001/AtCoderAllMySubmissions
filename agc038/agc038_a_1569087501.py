H,W,A,B = map(int,input().split())
HH = [0]*H
WW = [0]*W
HW = [[0]*W]*H
for _ in range(H):
    for i in range(W):
        if HH[_] < B and WW[i] < A:
            HW[_][i] = 1
            HH[_] += 1
            WW[i] += 1
for _ in range(H):
    print(int("".join(map(str, HW[_]))))









