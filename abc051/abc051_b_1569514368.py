K,S = map(int,input().split())
x = 0
for i in range(K+1):
    if S-i > 2*K:
        continue
    else:
        for l in range(K+1):
            if S-i-l > K or i+l > S:
                continue
            else:
                x += 1
print(x)