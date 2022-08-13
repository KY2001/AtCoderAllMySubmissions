A,B,C,X = map(int,open(0).read().split())
a = 0
for i in range(1,A+1):
    for l in range(1,B+1):
        for q in range(1,C+1):
            if 500*i+100*B+50*C == X:
                a += 1
print(a)