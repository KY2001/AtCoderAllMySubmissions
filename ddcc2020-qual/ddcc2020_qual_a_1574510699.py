ans = 0
num = list(map(int,input().split()))
for i in range(2):
    if num[i] == 1:
        ans += 300000
    elif num[i] == 2:
        ans += 200000
    elif num[i] == 3:
            ans += 100000
if num[1] == num[0] == 1:
    ans += 400000
print(ans)