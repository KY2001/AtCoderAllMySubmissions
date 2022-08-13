N = int(input())
H = list(map(int,input().split()))
t = 0
h = 0
for i in H:
    if i >= h:
        t += 1
        h = i
print(t)