H,W,A,B = map(int,input().split())
HH = [0]*H
WW = [0]*W
HW = [[0]*W for _ in range(H)]
for ii in range(H):
    for i in range(W):
        if HH[ii] < A and WW[i] < B:
                HW[ii][i] = 1
                HH[ii] += 1
                WW[i] += 1
for s in range(H):
    print("".join(map(str, HW[s])))

