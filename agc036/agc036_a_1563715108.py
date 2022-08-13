S = int(input())
import sys
if S <= 10**9 :
    A = [0,0,1,0,0,S]
    print(*A)
elif S<= 10**16:
    for i in range(0,10**9+1):
        a = 10**9 * i
        if S < a <= S+10**9:
            print(*[0,0,10**9,1,int(i),int(a-S)])
            sys.exit()
else:
    for i in range(1,101):
        c = 10**16 * i
        if c < S <= c+10**16:
            for b in range(10**7*i, 10**7*(i+1)):
                a = 10 ** 9 * b
                if S < a <= S + 10 ** 9:
                    print(*[0, 0, 10 ** 9, 1, int(i), int(a - S)])
                    sys.exit()

