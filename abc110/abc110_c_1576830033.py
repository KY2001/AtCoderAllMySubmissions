S = input()
T = input()

SS = sorted(list(S))
TT = sorted(list(T))
SSS = []
TTT = []
numS = 0
numT = 0
checkS = 1
checkT = 1

for i in range(len(S)-1):
    if SS[i] != SS[i+1]:
        SSS.append(checkS)
        checkS = 1
    elif i == len(S)-2:
        SSS.append(checkS+1)
    else:
        checkS += 1

    if TT[i] != TT[i+1]:
        TTT.append(checkT)
        checkT = 1
    elif i == len(S)-2:
        TTT.append(checkT+1)
    else:
        checkT += 1
SSS.sort()
TTT.sort()
if SSS == TTT:
    print("Yes")
else:
    print("No")