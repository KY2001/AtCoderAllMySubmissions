N = int(input())
if N % 2 == 0:
    print(int(((N+1)*N/2)-N))
else:
    print(int(((N+1)*((N-1)/2))+(((N-1)/2)+1) - N))