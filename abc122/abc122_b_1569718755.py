S = list(input())
s = 0
t = 0
c = {"A","C","G","T"}
for i in S:
    if i in c:
        s += 1
    else:
        s = 0
    if s > t:
        t = s
print(t)
