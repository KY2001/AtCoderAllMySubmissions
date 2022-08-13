N = int(input())
S = input()
NN = N//2
c = "b"
for i in range(1,NN+1):
    if i%3 == 1:
        c = "a"+c+"c"
    elif i%3 == 2:
        c = "c"+c+"a"
    else:
        c = "b"+c+"b"
if c == S:
    print(N//2)
else:
    print(-1)

