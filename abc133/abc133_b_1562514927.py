N,D = map(int,input().split())
A=[]
C=0
E=0
Z=0
for i in range (1,N+1):
    A.append(i)
for i in range (0,N):
    A[i]=list(map(int,input().split()))
for i in range (0,N-1):
    for j in range(i,N-1):
        for k in range(0,D):
            B=(A[i][k]-A[j+1][k])**2
            C+=B
        Z=C
        C=0
        if (Z**(1/2))%1==0:
            E+=1
print(E)