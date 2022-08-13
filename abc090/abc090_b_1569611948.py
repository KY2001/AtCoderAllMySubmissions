A,B = map(int,input().split())
s = 0
for i in range(A,B+1):
    AB = list(str(i))
    if AB == [AB[-(i+1)] for i in range(len(AB))]:
        s += 1
print(s)