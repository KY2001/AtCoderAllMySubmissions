N = int(input())
L = list("00:00:00")
a = list(str(N//3600))
b = list(str((N-(3600*(N//3600)))//60))
c = list(str(N%60))
abc = [a,b,c]
for i in range(3):
    if len(abc[i]) == 2:
        L[3*i] = abc[i][0]
        L[3*i+1] = abc[i][1]
    elif len(abc[i]) == 1:
        L[3*i+1] = abc[i][0]
print("".join(L))
