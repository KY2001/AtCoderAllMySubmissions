N = input()
NN = list(N)
checker = ""
for i in range(len(NN)):
    checker += NN[-1]
if N == checker:
    print("Yes")
else:
    print("No")