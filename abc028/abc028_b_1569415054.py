S = list(input())
C = ["A","B","C","D","E","F"]
R = []
for i in C:
    s = 0
    for l in S:
        if l == i:
            s += 1
    R.append(str(s))
print(" ".join(R))