N = int(input())
H = list(map(int, input().split()))
s = 0
t = 0
for i in range(N-1):
    if H[i] >= H[i+1]:
        s += 1
    elif s > t:
        t = s
        s = 0
    else:
        s = 0
print(max(s,t))


