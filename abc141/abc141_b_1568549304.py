A = str(input())
B = len(A)
C = list(A)
t = 0
for i in range(B):
    if i % 2 == 1:
        if C[i] == "L" or C[i] =="U" or C[i] =="D":
            t += 1
    else:
        if  C[i] == "R"or C[i] == "U" or C[i] =="D":
            t += 1
if t == B  :
    print("Yes")
else:
    print("No")














