N = int(input())
t = 0
for i in range(N):
    s = 0
    if (i+1)%2 == 0:
        continue
    else:
        for l in range(i+1):
            if (i + 1) % (l + 1) == 0:
                s += 1
        if s == 8:
            t += 1
print(t)

