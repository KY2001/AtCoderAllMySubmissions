import sys
s = list(input())
t = len(s)
for i in range(len(s)):
    if s[i] == "C":
        t = i
        break
for i in range(t,len(s)):
    if s[i] == "F":
        print("Yes")
        sys.exit()
print("No")