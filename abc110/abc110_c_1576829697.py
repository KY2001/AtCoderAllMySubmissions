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
        if numS < checkS:
            numS = checkS
        SSS.append(numS)
        checkS = 1
    elif i == len(S)-1:
        SSS.append(numS)
    else:
        checkS += 1

    if TT[i] != TT[i+1]:
        if numT < checkT:
            numT = checkT
        TTT.append(numT)
        checkT = 1
    elif i == len(S)-1:
        TTT.append(numT)
    else:
        checkT += 1
SSS.sort()
TTT.sort()
if SSS == TTT:
    print("Yes")
else:
    print("No")