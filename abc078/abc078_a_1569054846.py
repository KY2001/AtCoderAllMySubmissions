X,Y = map(str,input().split())
XY = ["A","B","C","D","E","F"]
for i in range(5):
    if X == XY[i]:
        XX = i
    if Y == XY[i]:
        YY = i
if XX == YY:
    print("=")
elif XX > YY:
    print(">")
else:
    print("<")
    