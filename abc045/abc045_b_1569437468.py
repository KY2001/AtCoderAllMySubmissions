Sa = list(input())
Sb = list(input())
Sc = list(input())
for _ in range(10**8):
    if _ == 0:
        s = Sa[0]
        if s == "a":
            s = Sa[1]
            del Sa[0]
        elif s == "b":
            s = Sb[1]
            del Sb[0]
        else:
            s = Sc[1]
            del Sc[0]
    elif len(Sa) == 1 and s == "a":
        print("A")
        break
    elif len(Sb) == 1 and s == "b":
        print("B")
        break
    elif len(Sc) == 1 and s == "c":
        print("C")
        break
    else:
        if s == "a":
            s = Sa[1]
            del Sa[0]
        elif s == "b":
            s = Sb[1]
            del Sb[0]
        else:
            s = Sc[1]
            del Sc[0]
