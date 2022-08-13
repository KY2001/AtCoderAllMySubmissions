s = 1
for i in range(int(input())):
    s = (s*(i+1))%(10**9+7)
print(s)