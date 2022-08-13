import math
N = int(input())
ABC = [int(input()) for i in range(5)]
num = [N,0 ,0 ,0, 0,0]
t = 0

while True:
    num2 = [0 for l in range(5)]
    for i in range(5):
        if num[i] >= ABC[i]:
            num[i] -= ABC[i]
            num2[i] = ABC[i]
        elif num[i] != 0:
            num2[i] = num[i]
            num[i] = 0
    for l in range(5):
        num[l + 1] += num2[l]
    t += 1
    if num[5] == N:
        print(t)
        break
