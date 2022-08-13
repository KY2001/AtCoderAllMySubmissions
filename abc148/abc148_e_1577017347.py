N = int(input())
ans = 0
if N%2 == 0:
    for i in range(10**5):
        if 5**(i+1) > N:
            break
        ans += int((N)//5**(i+1))
    print(ans)
else:
    print(0)
