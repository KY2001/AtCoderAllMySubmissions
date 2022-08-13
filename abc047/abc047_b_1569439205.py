W,H,N = map(int,input().split())
S = [0,0,W,H]
for i in range(N):
    x,y,a = map(int,input().split())
    if a == 1 and x > S[0]:
        S[0] = x
    elif a == 2 and x <  S[2]:
        S[2] = x
    elif a == 3 and y > S[1]:
        S[1] = y
    elif a == 4 and y < S[3]:
        S[3] = y
if (S[2]-S[0])*(S[3]-S[1]) < 0 or S[0] >= S[2] or S[1] >= S[3]:
    print(0)
else:
    print((S[2] - S[0]) * (S[3] - S[1]))