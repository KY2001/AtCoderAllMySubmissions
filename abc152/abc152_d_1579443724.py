N = int(input())
t = [0 for _ in range(81)]
ans = 0
for i in range(1, 10):
    for l in range(1, 10):
        for q in range(1, N+1):
            s = 0
            a = str(q)[0]
            b = str(q)[-1]
            if int(a) == i and int(b) == l:
                s += 1
            t[9*(i - 1)+l - 1] += s
for i in range(1, N+1):
    a = str(i)[0]
    b = str(i)[-1]
    if b == "0":
        continue
    elif a == b:
        ans += t[9*(int(a)-1)+int(a)-1]
    else:
        ans += t[9*(int(b)-1)+int(a)-1]
print(ans)
