import sys
S = list(input())
N = len(S)
if S[0] == "A":
    s = 0
    for i in S[2:len(S)-1]:
        if i == "C":
            s += 1
    if s == 1:
        c = 0
        for i in S:
            if i.islower():
                 c += 1
        if c == N-2:
            print("AC")
            sys.exit()
print("WA")


