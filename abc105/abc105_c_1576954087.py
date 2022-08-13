import math
N= int(input())
ans = []
if N == 0:
    print(0)
else:
    for i in range(10**9):
        ans.append(str(abs(N%-2)))
        N = math.ceil(N/-2)
        if N == 1:
            break
    ans.append("1")
    ans2 = [ans[-i] for i in range(1, len(ans) + 1)]
    print("".join(ans2))
