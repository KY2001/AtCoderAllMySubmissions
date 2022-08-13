import math
import copy
D, G = map(int, input().split())
pc = [list(map(int, input().split())) for _ in range(D)]
aveP = [[(100*(i+1)*pc[i][0]+pc[i][1])/pc[i][0], i, pc[i][0], (100*(i+1)*pc[i][0]+pc[i][1])] for i in range(D)]
aveP2 = aveP
ans = 0
for i in range(D):
    if G <= 100*(i+1)*pc[i][0]:
        aveP2[i][0] = 100*(i+1)
aveP2.sort()
aveP3 = copy.deepcopy(aveP2)
for i in range(D):
    c = aveP3[i][1]
    aveP3[i][1] = aveP3[i][0]
    aveP3[i][0] = c
aveP3.sort()
p = 0
for i in range(1,D+1):
    for l in range(1,len(aveP3)+1):
        if G <= 100 * (aveP3[-l][0] + 1) * aveP3[-l][2] and aveP2[-i][2] > math.ceil(G / (100 * (aveP3[-l][0] + 1))) :
            ans += math.ceil(G / (100 * (aveP3[-l][0] + 1)))
            p = 1
            break
    if p == 1:
        break
    G -= aveP2[-i][3]
    ans += aveP2[-i][2]
    for l in range(len(aveP3)):
        if aveP3[l][0] == aveP2[-i][1] and aveP3[l][1] == aveP2[-i][0] and aveP3[l][2] == aveP2[-i][2] and aveP3[l][3] == aveP2[-i][3]:
            del aveP3[l]
            break
    if G <= 0:
        break
print(ans)