N = int(input())
s = []
l = 0
for i in range(0,N):
    s.append(str(input()))
for i in range(0,N):
    s[i] = ''.join(sorted(s[i]))
s.sort()
for i in range(0,N-1):
    for n in range(i+1,N):
        if s[i] == s[n]:
            l += 1
print(l)
