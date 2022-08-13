N = int(input())
value = [[59,"Bad"],[89,"Good"],[99,"Great"],[100,"Perfect"]]
for i in range(4):
    if N <= value[i][0]:
        print(value[i][1])
        break