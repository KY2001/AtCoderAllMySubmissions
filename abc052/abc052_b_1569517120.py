N = int(input())
S = list(input())
m = 0
x = 0
for i in range(N):
    if S[i] == "I":
        x += 1
    else:
        x -= 1
    if x > m:
        m = x
print(m)
