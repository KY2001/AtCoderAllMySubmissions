N = int(input())
t = [[0 for _ in range(9)] for l in range(9)]
ans = 0
for i in range(1, N+1):
    if len(str(i)) == 1:
        t[i-1][i-1] += 1
    elif str(i)[-1] != "0":
        t[int(str(i)[0])-1][int(str(i)[-1])-1] += 1
for i in range(1, N+1):
    a = str(i)[0]
    b = str(i)[-1]
    if b == "0":
        continue
    elif a == b:
        ans += t[(int(a)-1)][int(a)-1]
    else:
        ans += t[(int(b)-1)][int(a)-1]
print(ans)
