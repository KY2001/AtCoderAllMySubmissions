S = input()
A = sorted([S,"2019/04/30"])
if A[0] == A[1]:
    print("Heisei")
elif A[0] == "2019/04/30":
    print("TBD")
else:
    print("Heisei")
