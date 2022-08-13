S = list(input())
s = 0
if S[0] == "B":
    for i in range(len(S)-1):
        if S[i] == "B"and S[i+1] == "W":
            s += 1
else:

    for i in range(len(S)-1):
        if S[i] == "W"and S[i+1] == "B":
            s += 1
print(s*2-1)