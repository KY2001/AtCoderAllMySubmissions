s = list(input())
for i in range(len(s)):
    if s[i] == 'A':
        A = i
        break
for i in range(len(s)):
    if s[-(i+1)] == 'Z':
        Z = len(s)-i
        break
print(Z-A)
