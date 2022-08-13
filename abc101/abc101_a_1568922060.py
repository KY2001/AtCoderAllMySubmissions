S = list(input())
a = 0
for i in range(4):
    if S[i] == "+":
        a += 1
    else:
        a -= 1
print(a)
        
