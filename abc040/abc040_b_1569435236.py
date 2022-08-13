n = int(input())
c = n
for s in range(n):
    for l in range((n//(s+1))+1):
        if (n-(s+1)*(l+1)) >= 0 and c > (n-(s+1)*(l+1))+abs(s-l) >= 0:
            c = (n-(s+1)*(l+1))+abs(s-l)
print(c)
