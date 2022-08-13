N = int(input())
S = input()
SS = list(S)
SSS = []
if N%2 != 0:
    print("No")
else:
    for i in range(int(N/2)):
        SSS.append(SS[i])
    SSS = "".join(SSS)
    SSS += SSS
    if SSS == S:
        print("Yes")
    else:
        print("No")
