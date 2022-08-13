X = int(input())
a = 0
for i in range(1,X+1):
    for l in range(2,11):
        if i**l <= X and i**l > a:
            a = i**l
print(a)