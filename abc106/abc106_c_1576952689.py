S = list(input())
K = int(input())

S = [int(i) for i in S]
for i in range(len(S)):
    if S[i] == 1:
        K -= 1
    else:
        print(S[i])
        break
    if K == 0:
        print(1)
        break
