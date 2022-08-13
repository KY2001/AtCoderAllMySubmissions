m = int(input())/1000
if m < 0.1:
    print("00")
elif m <= 5:
    if 10*m < 10:
        print("0" + str(int(10*m)))
    else:
        print(str(int(10*m)))
elif m <= 30:
    print(str(int(m+50)))
elif m <= 70:
    print(str(int(80+(m-30)/5)))
else:
    print("89")
