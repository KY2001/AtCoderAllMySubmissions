S = int(input())
import sys
if S <= 10**9 :
    A = [0,0,1,0,0,S]
    print(*A)
else:
    for i in range(1,10**10+1):
        a = 10**9 * i
        if S < a <= S+10**9:
            print(*[0,0,10**9,1,int(i),int(a-S)])
            sys.exit()




