a = (1,3,5,7,8,10,12)
b = (4,6,9,11)
c = (2,)
abc = [a,b,c]
x,y = map(int,input().split())
for i, checker in enumerate(abc):
    if x in checker:
        checker2 = checker
if y in checker2:
    print("Yes")
else:
    print("No")
