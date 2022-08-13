s = sorted(list(input()))
t = sorted(list(input()),reverse= True)
st = sorted([s,t])
if s == t:
    print("No")
elif st[0] == s:
    print("Yes")
else:
    print("No")
