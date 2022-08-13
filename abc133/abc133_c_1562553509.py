L,R=map(int,input().split())
M=2019
import sys
for i in range(L,R):
    for j in range(i+1,R+1) :
        if (i*j)%2019 < M :
            if M=0:
                sys.exit()
            M = (i*j)%2019
    
 print(M)