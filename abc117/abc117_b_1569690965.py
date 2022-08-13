N,*L = map(int,open(0).read().split())
L.sort()
if sum(L[::-1]) >L[-1]:
    print("Yes")
else:
    print("No")