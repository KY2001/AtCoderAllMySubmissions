S = list(input())
C = ["A","B","C","D","E","F"]
for i in C:
    s = 0
    for l in S:
        if l == i:
            s += 1
    print(s)