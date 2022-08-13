N =int(input())
S = input()
S = list(S)
p = 0
for i in range(N-2):
    if S[i] == "A" and S[i+1] == "B" and S[i+2] == "C":
        p += 1
print(p)
