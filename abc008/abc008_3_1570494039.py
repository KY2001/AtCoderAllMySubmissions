def ABC008C(a, b):
    "ABC008Cの答えを出力する。"
    b.sort()
    q = []
    s = 0
    for i in b:
        c = 0
        for l in b:
            if i % l == 0:
                c += 1
        q.append([i, c-1])
    for i in q:
        if i[1] % 2 == 1:
            s += 1 / 2
        else:
            s += (i[1] + 2) / (2*i[1] + 2)
    return s


N = int(input())
C = [int(input()) for _ in range(N)]
print(ABC008C(N, C))
