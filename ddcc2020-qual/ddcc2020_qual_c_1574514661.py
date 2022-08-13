H, W, K = map(int,input().split())
output = []
c = 1
for i in range(H):
    s = list(input())
    t = -1
    output.append([])
    for l in range(W):
        if s[l] == '#':
            for q in range(l-t):
                output[i].append(str(c))
            c += 1
            t = l
        elif l == W-1:
            for q in range(l-t):
                output[i].append(str(c-1))
for i in range(H):
    print(" ".join(output[i]))

