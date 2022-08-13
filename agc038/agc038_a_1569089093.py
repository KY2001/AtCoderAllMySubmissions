H,W,A,B = map(int,input().split())
Hcount = [0] * H
Wcount = [0] * W
HW = [[0 for i in range(W)] for _ in range(H)]
for i in range(H):
    for _ in range(W):
        if Hcount[i] < B and Wcount[_] < A:
            HW[i][_] = 1
            Hcount[i] += 1
            Wcount[_] += 1
print(HW)
for s in range(H):
    print("".join(map(str, HW[s])))
