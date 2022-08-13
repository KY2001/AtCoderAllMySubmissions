N = int(input())
a = list(map(int,input().split()))
ans = 0
for i in a:
    if i%2 == 0:
        c = 0
        for l in range(30):
            i /= 2
            c += 1
            if i%2 != 0:
                ans += c
                break
print(ans)