s = list(input())
ss = []
c = 1
for i in range(1,len(s)):
    if s[i] == s[i-1]:
        c += 1
        if i == len(s)-1:
            ss.append(s[i] + str(c))
    else:
        ss.append(s[i-1]+str(c))
        c = 1
        if i == len(s)-1:
            ss.append(s[i] + str(c))
print("".join(ss))