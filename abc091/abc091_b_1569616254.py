N = int(input())
s = [input() for _ in range(N)]
M = int(input())
t = [input() for _ in range(M)]
ss = set(s)
b = 0
for i in ss:
    a = 0
    for l in s:
        if l == i:
            a += 1
    for l in t:
        if l == i:
            a -= 1
    if a > b:
        b = a
print(b)

