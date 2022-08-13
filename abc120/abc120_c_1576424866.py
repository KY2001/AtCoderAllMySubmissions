S = list(input())
c = 0
for i in range(len(S)):
    if S[i] == '0':
        c += 1
print(2*min(c, len(S)-c))