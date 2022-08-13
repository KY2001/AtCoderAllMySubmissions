s = list(input())
k = int(input())
C = set()
for i in range(len(s)-k+1):
    ss = "".join(s[i:i+k])
    if ss not in C:
        C.add(ss)
print(len(C))