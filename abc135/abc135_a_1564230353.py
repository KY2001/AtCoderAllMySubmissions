A, B = map(int,input().split())
if (A+B)%2 == 1:
    print('IMPOSSIBLE')
else:
    print(int((A+B)/2))
