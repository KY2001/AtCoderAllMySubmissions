A,B,C =(int (i) for i in input().split())
z = A - B
d = C - z
if d < 0:
    d = 0
print(int(d))