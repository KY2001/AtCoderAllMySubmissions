s = f = int(input())
ss = []
for i in range(10**8):
    if f%2 == 0:
        f //= 2
    else:
        f = 3*f+1
    ss.append(f)
    if len(set(ss)) != i+1:
        print(i+2)
        break