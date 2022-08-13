S = list(input())
s = []
for i in range(len(S)-2):
    s.append(abs(int(S[i]+S[i+1]+S[i+2])-753))
s.sort()
print(s[0])


