H,W,A,B = map(int,input().split())
c = ""
cc = ""
if A > H or B > W:
    print("No")
else:
    for _ in range(A):
        c += "0"
        cc += "1"
    for _ in range(W-A):
        c += "1"
        cc += "0"
    for i in range(B-1):
        print(c)
    for i in range(H-B+1):
        print(cc)

