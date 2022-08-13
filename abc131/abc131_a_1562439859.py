A=str(input () )
B=0
while B!=3:
    if A[B]==A[B+1]:
        print('Bad')
        break
    else:    
        B=B+1
else:
    print('Good')    