import copy
import sys
S = list(input())
SS = copy.deepcopy(S)
s = 1
ss = 1
if len(S) == 1:
    print(0)
    sys.exit()

for i in range(len(S)-1):
    if S[i] == S[i+1] == '0':
        S[i] = '1'
        for l in range(i+1, len(S)-1):
            if S[l] == S[l+1] == '0':
                S[l+1] = '1'
                s += 1
            elif S[l] == S[l+1] == '1':
                S[l+1] = '0'
                s += 1
        break
    elif S[i] == S[i+1] == '1':
        S[i] = '0'
        for l in range(i+1, len(S)-1):
            if S[l] == S[l+1] == '0':
                S[l+1] = '1'
                s += 1
            elif S[l] == S[l+1] == '1':
                S[l+1] = '0'
                s += 1
        break

S = SS
for i in range(len(S)-1):
    if S[i] == S[i+1] == '0':
        S[i+1] = '1'
        for l in range(i+1, len(S)-1):
            if S[l] == S[l+1] == '0':
                S[l+1] = '1'
                ss += 1
            elif S[l] == S[l+1] == '1':
                S[l+1] = '0'
                ss += 1
        break
    elif S[i] == S[i+1] == '1':
        S[i+1] = '0'
        for l in range(i+1, len(S)-1):
            if S[l] == S[l+1] == '0':
                S[l+1] = '1'
                ss += 1
            elif S[l] == S[l+1] == '1':
                S[l+1] = '0'
                ss += 1
        break

print(min(s,ss))