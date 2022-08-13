N = int(input())
S = list(input())
S = [int(S[i]) for i in range(N)]
count = 0
for i in range(10):
    for l in range(10):
        for q in range(10):
            t = 0
            for s in range(N):
                if t == 1:
                    break
                if S[s] == i:
                    p = s
                    for r in range(p + 1, N):
                        if t == 1:
                            break
                        if S[r] == l:
                            p = r
                            for b in range(p + 1, N):
                                if t == 1:
                                    break
                                if S[b] == q:
                                    count += 1
                                    t = 1
                                    break
                                elif b == N - 1:
                                    t = 1
                        elif r == N-1:
                            t = 1
                elif s == N - 1:
                    t = 1
print(count)
