N = int(input())
s = []
l = 1
z = 0
s = [input() for _ in range(N)]
for i in range(0,N):
    s[i] = ''.join(sorted(s[i]))
s.sort()
for i in range(0,N-1):
    if s[i] == s[i+1]:
        l += 1
    else:
        z += l*(l-1)/2
        l = 1
z += l*(l-1)/2
print(int(z))
