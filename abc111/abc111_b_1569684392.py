N = int(input())
for i in range(N,1000+N):
    if len(set(list(str(i)))) == 1:
        print(i)
        break