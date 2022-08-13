n=int(input())
b=list(map(int,input().split()))
c=0
d=0
while c<=n-2 :
    if b[c+1]>b[c] and b[c+1]<b[c+2] or b[c+1]<b[c] and b[c+1]>b[c+2]:
        d +=1
        c +=1
    else:
        c+=1

print(d)
