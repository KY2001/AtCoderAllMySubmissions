N,*A = map(int,open(0).read().split())
AA = set()
s = 0
for i in A:
    if i not in AA:
        AA.add(i)
    else:
        s += 1
print(s)