A,B,C =input().split()
z = int(A) - int(B)
d = int(C) - z
if d < 0:
    d = 0
print(int(d))