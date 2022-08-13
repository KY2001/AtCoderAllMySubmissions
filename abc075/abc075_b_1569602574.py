H,W = map(int,input().split())
S = [list(input()) for _ in range(H)]
for i in range(H):
    for l in range(W):
        if S[i][l] == ".":
            s = 0
            if l <= W-2:
                if S[i][l+1] == "#":
                    s += 1
            if l >= 1:
                if S[i][l-1] == "#":
                    s += 1
            if i >= 1 and l <= W-2:
                if S[i-1][l+1] == "#":
                    s += 1
            if i >= 1:
                if S[i-1][l] == "#":
                    s += 1
            if i >= 1 and l >= 1:
                if S[i-1][l-1] == "#":
                    s += 1
            if i <= H-2 and l <= W-2:
                if S[i+1][l+1] == "#":
                    s += 1
            if i <= H-2:
                if S[i+1][l] == "#":
                    s += 1
            if i <= H-2 and l >= 1:
                if S[i+1][l-1] == "#":
                    s += 1
            S[i][l] = str(s)
for i in range(H):
    print("".join(S[i]))



