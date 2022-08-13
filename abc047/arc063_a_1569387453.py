S = list(input())
s = 0
for i in range(len(S)-1):
    if S[i] != S[i+1]:
        s += 1
print(s)