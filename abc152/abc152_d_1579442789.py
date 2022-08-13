N = int(input())
t = [[0 for i in range(9)] for _ in range(9)]
ans = 0
for i in range(1, 10):
    for l in range(1, 10):
        for q in range(1, N+1):
            s = 0
            if int(str(q)[0]) == i and int(str(q)[-1]) == l:
                s += 1
            t[i - 1][l - 1] += s
for i in range(1, N+1):
    a = str(i)[0]
    b = str(i)[-1]
    if b == "0":
        continue
    elif a == b:
        ans += t[int(a)-1][int(a)-1]
    else:
        ans += t[int(b)-1][int(a)-1]
print(ans)
