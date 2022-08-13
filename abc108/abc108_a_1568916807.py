K = int(input())
if K%2 == 1:
    print(int((((K-1)/2)+1)*((K-1))/2))
else:
    print(int((K**2)/4))