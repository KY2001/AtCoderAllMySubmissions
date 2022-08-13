H, W, K = map(int,input().split())
output = []
c = 1
z = 0
for i in range(H):
    s = list(input())
    t = -1
    output.append([])
    for l in range(W):
        if s == ["."]*W and len(output) != 0:
            output[i] = output(i-1)
            break
        elif s == ["."]*W and len(output) == 0:
            z += 1
            break
        if s[l] == '#':
            for q in range(l-t):
                output[i].append(str(c))
            c += 1
            t = l
            if z != 0:
                for s in range(z):
                    output.append(output[0])
                z = 0
        elif l == W-1:
            for q in range(l-t):
                output[i].append(str(c-1))
            if z != 0:
                for s in range(z):
                    output.append(output[0])
                z = 0
for i in range(H):
    print(" ".join(output[i]))

