Sa = list(input())
Sb = list(input())
Sc = list(input())
c = 0
for _ in range(10**9):
    if c == "a" and not Sa:
        print("A")
        break
    if c == "b" and not Sb:
        print("B")
        break
    if c == "c" and not Sc:
        print("C")
        break
    if _ == 0:
        c = Sa[0]
        del Sa[0]
    elif c == "a":
        c = Sa[0]
        del Sa[0]
    elif c == "b":
        c = Sb[0]
        del Sb[0]
    else:
        c = Sc[0]
        del Sc[0]




