s = list(input())
a = []
for i in range(len(s)):
    if s[i] == "B" and a != []:
        del a[-1]
    elif s[i] == "B" and a == []:
        continue
    else:
        a.append(str(s[i]))
print("".join(a))