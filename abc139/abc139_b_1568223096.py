A,B = map(int,input().split())
s = 1
for i in range(30):
    if s >= B:
        print(i)
        break
    s += (A-1)
