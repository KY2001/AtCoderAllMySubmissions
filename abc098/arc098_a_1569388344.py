N = int(input())
S = list(input())
e = w = 0
m = 0
t = 0
for i in range(N):
    if S[i] == "W":
        w += 1
    else:
        e += 1
for i in range(N):
    if t == 1:
        w += 1
        t = 0
    if S[i] == "W":
        w -= 1
    else:
        t = 1
    if m < w:
        m = w
print(N-m-1)

