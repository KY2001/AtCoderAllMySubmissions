A,B,C,X = map(int,open(0).read().split())
a = 0
for i in range(A+1):
    for l in range(B+1):
        for q in range(C+1):
            if 500*i+100*l+50*q == X:
                a += 1
print(a)