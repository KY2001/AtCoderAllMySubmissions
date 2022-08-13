import sys
t = 0
s = list(input())
for i in range(len(s)):
    if s[i] == "C":
        t = i
        break
for i in range(t,len(s)):
    if s[i] == "F":
        print("Yes")
        sys.exit()
print("No")